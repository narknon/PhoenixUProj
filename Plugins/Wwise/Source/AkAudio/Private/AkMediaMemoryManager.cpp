/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/


#include "AkMediaMemoryManager.h"
#include "AkMediaAsset.h"
#include "AkAudioDevice.h"

AkMediaMemoryManager* AkMediaMemoryManager::Instance = nullptr;
DECLARE_STATS_GROUP(TEXT("AkAudioDevice"), STATGROUP_AkMediaMemoryManager, STATCAT_Audiokinetic);
DECLARE_CYCLE_STAT(TEXT("AkCleanUpMediaMemory"), STAT_CleanUpMediaMemory, STATGROUP_AkMediaMemoryManager);
DECLARE_MEMORY_STAT(TEXT("AkMediaMemoryAllocated"), STAT_AkMediaMemoryAllocated, STATGROUP_Memory);
DECLARE_MEMORY_STAT(TEXT("AkMediaDeviceMemoryAllocated"), STAT_AkMediaDeviceMemoryAllocated, STATGROUP_Memory);
AkMediaMemoryManager::AkMediaMemoryManager()
{
	if (Instance != nullptr)
	{
		UE_LOG(LogInit, Error, TEXT("AkMediaMemoryManager has already been instantiated."));
	}

	Instance = this;
	StartCleanUpEvent = FPlatformProcess::GetSynchEventFromPool(true);
	Thread = FRunnableThread::Create(this, TEXT("AkMediaMemoryManager ticker"));
}

AkMediaMemoryManager::~AkMediaMemoryManager()
{
	Stop();
	Instance = nullptr;
	FPlatformProcess::ReturnSynchEventToPool(StartCleanUpEvent);
	StartCleanUpEvent = nullptr;
	UE_CLOG(MediaIDToMemoryMap.Num() > 0, LogAkAudio, Error, TEXT("Destroying AkMediaMemoryManager, but some media is still needed by Wwise. Leaking memory."));
}

AkMediaMemoryManager* AkMediaMemoryManager::Get()
{
	return Instance;
}

bool AkMediaMemoryManager::HasPendingMediaToRemove()
{
	return GetNumberOfEntriesToRemove() > 0;
}

uint8* AkMediaMemoryManager::AllocateMediaMemory(int64 DataSize, bool UseDeviceMemory)
{
#if AK_SUPPORT_DEVICE_MEMORY
	if (UseDeviceMemory)
	{
		INC_MEMORY_STAT_BY(STAT_AkMediaDeviceMemoryAllocated, DataSize);
		return (AkUInt8*)AKPLATFORM::AllocDevice(DataSize, 0);
	}
	else
#endif
	{
		INC_MEMORY_STAT_BY(STAT_AkMediaMemoryAllocated, DataSize);
		return static_cast<uint8*>(FMemory::Malloc(DataSize));
	}
}

void AkMediaMemoryManager::FreeMediaMemory(uint8* MediaMemory, int64 DataSize, bool UseDeviceMemory)
{
	if (!MediaMemory)
	{
		return;
	}

#if AK_SUPPORT_DEVICE_MEMORY
	if (UseDeviceMemory)
	{
		DEC_MEMORY_STAT_BY(STAT_AkMediaDeviceMemoryAllocated, DataSize);
		AKPLATFORM::FreeDevice(MediaMemory, DataSize, 0, true);
	}
	else
#endif
	{
		DEC_MEMORY_STAT_BY(STAT_AkMediaMemoryAllocated, DataSize);
		FMemory::Free(MediaMemory);
	}
}

void AkMediaMemoryManager::SetMedia(FString MediaName, uint32 MediaId, uint8* LoadedMediaData, int64 MediaDataSize)
{
	UE_LOG(LogAkAudio, Verbose, TEXT("AkMediaMemoryManager::SetMedia: Id is % u. Name is % s."), MediaId, *MediaName);

	if (MediaId != AK_INVALID_UNIQUE_ID)
	{
		AkSourceSettings SourceSettings
		{
			MediaId, reinterpret_cast<AkUInt8*>(LoadedMediaData), static_cast<AkUInt32>(MediaDataSize)
		};

		if (auto AkAudioDevice = FAkAudioDevice::Get())
		{
			UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::DoSetMedia: Setting media %u at address %p."), MediaId, LoadedMediaData);

			if (AkAudioDevice->SetMedia(&SourceSettings, 1) != AK_Success)
			{
				UE_LOG(LogAkAudio, Log, TEXT("SetMedia failed for %s - %u"), *MediaName, MediaId);
			}
		}
	}
}

bool AkMediaMemoryManager::RequestMediaMemory(FString MediaName, uint32 MediaId, int64 MediaSize, bool UseDeviceMemory, uint8*& out_MediaMemory)
{
	{
		FScopeLock Lock(&MediaIDToMemoryMapLock);
		FAkMediaMemoryEntry* FoundItem = MediaIDToMemoryMap.Find(MediaId);

		// Do we already know about this media?
		if (FoundItem)
		{
			FoundItem->RefCount++;
			UE_LOG(LogAkAudio, Verbose, TEXT("AkMediaMemoryManager::RequestMediaMemory: Memory was already allocated for media %s - %u, RefCount is now %d"), *MediaName, MediaId, FoundItem->RefCount);
			out_MediaMemory = FoundItem->MediaMemory;
			return true;
		}
	}

	out_MediaMemory = AllocateMediaMemory(MediaSize, UseDeviceMemory);
	if (out_MediaMemory)
	{
		if (UNLIKELY(MediaIDToMemoryMap.Contains(MediaId)))
		{
			UE_LOG(LogAkAudio, Warning, TEXT("Allocated media memory for a Media ID already accounted for."));
			FreeMediaMemory(out_MediaMemory, MediaSize, UseDeviceMemory);
			MediaIDToMemoryMap[MediaId].RefCount++;
			out_MediaMemory = MediaIDToMemoryMap[MediaId].MediaMemory;
			return true;
		}

		UE_LOG(LogAkAudio, Verbose, TEXT("AkMediaMemoryManager::RequestMediaMemory: Successfully allocated memory for media %s - %u"), *MediaName, MediaId);
		FScopeLock Lock(&MediaIDToMemoryMapLock);
		checkf(!MediaIDToMemoryMap.Contains(MediaId), TEXT("Allocated media memory for a Media ID already accounted for."));
		MediaIDToMemoryMap.Add(MediaId, { out_MediaMemory, 1, MediaSize, UseDeviceMemory });
	}
	else
	{
		UE_LOG(LogAkAudio, Error, TEXT("AkMediaMemoryManager::RequestMediaMemory: Unable to allocate memory for media %s - %u"), *MediaName, MediaId);
	}

	return false;
}

void AkMediaMemoryManager::ReleaseMediaMemory(uint32 MediaID)
{
	FAkMediaMemoryEntry* FoundItem = nullptr;
	{
		FScopeLock Lock(&MediaIDToMemoryMapLock);
		FoundItem = MediaIDToMemoryMap.Find(MediaID);
		if (FoundItem)
		{
			FoundItem->RefCount--;
			UE_LOG(LogAkAudio, Verbose, TEXT("AkMediaMemoryManager::ReleaseMediaMemory: Releasing media memory for media %u. RefCount is now %d"), MediaID, FoundItem->RefCount);
			if (UNLIKELY(FoundItem->RefCount<0))
			{
				FoundItem->RefCount = 0;
				UE_LOG(LogAkAudio, Warning, TEXT("AkMediaMemoryManager::ReleaseMediaMemory: Negative RefCount for media %u"), MediaID);
			}
		}
		else
		{
			UE_LOG(LogAkAudio, Warning, TEXT("AkMediaMemoryManager::ReleaseMediaMemory: Tried to release media memory for %u, but none was allocated."), MediaID);
		}
	}

	if (FoundItem && FoundItem->RefCount <= 0)
	{
		FlagIDForRemoval(MediaID);
		StartCleanUpEvent->Trigger();
	}
}

uint32 AkMediaMemoryManager::Run()
{
	while (1)
	{
		StartCleanUpEvent->Wait(1000);
		StartCleanUpEvent->Reset();
		CleanUpMedia();

		if (!bRunThread)
		{
			break;
		}


		FPlatformProcess::Sleep(0.1f);
	}
	return 0;
}

void AkMediaMemoryManager::Stop()
{
	bRunThread = false;
	StartCleanUpEvent->Trigger();
	Thread->WaitForCompletion();
}

void AkMediaMemoryManager::CleanUpMedia()
{
	auto* AudioDevice = FAkAudioDevice::Get();
	if (!AudioDevice)
	{
		return;
	}

	SCOPE_CYCLE_COUNTER(STAT_CleanUpMediaMemory);

	bool bPendingMediaToRemove = GetNumberOfEntriesToRemove() >0;

	uint32 IDToRemove = AK_INVALID_UNIQUE_ID;
	TArray<uint32> IDsStillNeeded;
	while ((IDToRemove = GetNextIDToRemove()) != AK_INVALID_UNIQUE_ID)
	{
		FScopeLock Lock(&MediaIDToMemoryMapLock);
		FAkMediaMemoryEntry* FoundItem = MediaIDToMemoryMap.Find(IDToRemove);
		if (UNLIKELY(!FoundItem || FoundItem->RefCount > 0))
		{
			continue;
		}

		UE_LOG(LogAkAudio, Verbose, TEXT("AkMediaMemoryManager::CleanUpMedia: Attempting to unset media %u"), IDToRemove);
		AkSourceSettings SourceSettings
		{
			IDToRemove, reinterpret_cast<AkUInt8*>(FoundItem->MediaMemory), static_cast<AkUInt32>(FoundItem->DataSize)
		};

		AKRESULT AkResult = AudioDevice->TryUnsetMedia(&SourceSettings, 1);
		if (AkResult != AK_ResourceInUse)
		{
			UE_LOG(LogAkAudio, Verbose, TEXT("AkMediaMemoryManager::CleanUpMedia: Unset media successful for %u"), IDToRemove);
			FreeMediaMemory(FoundItem->MediaMemory, FoundItem->DataSize, FoundItem->bUseDeviceMemory);
			MediaIDToMemoryMap.Remove(IDToRemove);
		}
		else
		{
			UE_LOG(LogAkAudio, Verbose, TEXT("AkMediaMemoryManager::CleanUpMedia: Unable to unset media %u because Wwise still needs it."), IDToRemove);
			IDsStillNeeded.Add(IDToRemove);
		}
	}

	if (bPendingMediaToRemove && GetNumberOfEntriesToRemove() == 0)
	{
		OnAllPendingMediaFreed.Broadcast();
	}

	FlagIDsForRemoval(IDsStillNeeded);
}


int AkMediaMemoryManager::GetNumberOfEntriesToRemove( ) 
{
	FScopeLock Lock(&EntriesToRemoveLock);
	return EntriesToRemove.Num();
}

void AkMediaMemoryManager::FlagIDForRemoval(uint32 MediaID)
{
	FScopeLock Lock(&EntriesToRemoveLock);
	EntriesToRemove.Push(MediaID);
}

void AkMediaMemoryManager::FlagIDsForRemoval(const TArray<uint32>& MediaIDs)
{
	FScopeLock Lock(&EntriesToRemoveLock);
	EntriesToRemove.Append(MediaIDs);
}

uint32 AkMediaMemoryManager::GetNextIDToRemove()
{
	FScopeLock Lock(&EntriesToRemoveLock);
	if (EntriesToRemove.Num() == 0)
	{
		return AK_INVALID_UNIQUE_ID;
	}
	return EntriesToRemove.Pop();
}
