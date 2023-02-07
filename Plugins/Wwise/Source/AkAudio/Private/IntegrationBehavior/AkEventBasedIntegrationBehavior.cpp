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

#include "AkEventBasedIntegrationBehavior.h"

#include "UObject/UObjectIterator.h"
#include "Async/Async.h"
#include "AkAssetBase.h"
#include "AkAudioBank.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkInitBank.h"
#include "AkMediaAsset.h"
#include "AkMediaMemoryManager.h"
#include "AkUnrealHelper.h"
#include "AkUnrealIOHook.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "Core/Public/Misc/Paths.h"

namespace AkEventBasedHelpers
{
	template <typename E>
	constexpr typename std::underlying_type<E>::type to_underlying(E e) noexcept
	{
	    return static_cast<typename std::underlying_type<E>::type>(e);
	}

	AKRESULT LoadBankFromMemoryInternal(FAkAudioDevice* AudioDevice, int64 DataBulkSize, AkBankID& BankID, const void*& RawData)
	{
		auto result = AudioDevice->LoadBankFromMemory(RawData, static_cast<uint32>(DataBulkSize), BankID);

		UE_LOG(LogAkAudio, Verbose, TEXT("LoadBank returned %d"), to_underlying<AKRESULT>(result));
		if (result != AK_Success && result != AK_BankAlreadyLoaded)
		{
			BankID = AK_INVALID_BANK_ID, RawData = nullptr;
		}
		return result;
	}
}

// AkAssetData
AKRESULT AkEventBasedIntegrationBehavior::AkAssetData_LoadBank(UAkAssetData* AkAssetData)
{
	auto AudioDevice = FAkAudioDevice::Get();
	if (!AudioDevice)
		return AK_Success;

	auto dataBulkSize = AkAssetData->Data.GetBulkDataSize();
	if (dataBulkSize <= 0)
		return AK_Success;

#if WITH_EDITOR
	AkAssetData->EditorRawData.Reset(dataBulkSize);
	AkAssetData->RawData = FMemory::Memcpy(AkAssetData->EditorRawData.GetData(), AkAssetData->Data.LockReadOnly(), dataBulkSize);
	AkAssetData->Data.Unlock();
	return AkEventBasedHelpers::LoadBankFromMemoryInternal(AudioDevice, dataBulkSize, AkAssetData->BankID, AkAssetData->RawData);
#else
	AkAssetData->RawData = AkAssetData->Data.LockReadOnly();
	auto result = AkEventBasedHelpers::LoadBankFromMemoryInternal(AudioDevice, dataBulkSize, AkAssetData->BankID, AkAssetData->RawData);
	AkAssetData->Data.Unlock();
	return result;
#endif
}

// AkAudioBank
void AkEventBasedIntegrationBehavior::AkAudioBank_Load(UAkAudioBank* AkAudioBank)
{
	if (AkAudioBank->IsLocalized())
	{
		if (auto* audioDevice = FAkAudioDevice::Get())
		{
			AkAudioBank->LoadLocalizedData(audioDevice->GetCurrentAudioCulture());
		}
	}
	else
	{
		AkAudioBank->AssetBaseLoadBank();
	}
}

void AkEventBasedIntegrationBehavior::AkAudioBank_Unload(UAkAudioBank* AkAudioBank)
{
	AkAudioBank->AssetBaseUnloadBank();
}

// AkAudioDevice
AKRESULT AkEventBasedIntegrationBehavior::AkAudioDevice_ClearBanks(FAkAudioDevice* AkAudioDevice)
{
	return AK_Success;
}

AKRESULT AkEventBasedIntegrationBehavior::AkAudioDevice_LoadInitBank(FAkAudioDevice* AkAudioDevice)
{
	if (AkAudioDevice->InitBank)
	{
		return AK_Success;
	}

	auto& assetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	TArray<FAssetData> initBankAssets;
	assetRegistryModule.Get().GetAssetsByClass(UAkInitBank::StaticClass()->GetFName(), initBankAssets);

	if (initBankAssets.Num() > 0)
	{
		AkAudioDevice->InitBank = Cast<UAkInitBank>(initBankAssets[0].GetAsset());
		AkAudioDevice->InitBank->LoadBank();
		AkAudioDevice->InitBank->AddToRoot(); // Prevent InitBank for being garbage collected

		return AK_Success;
	}

	return AK_Fail;
}

bool AkEventBasedIntegrationBehavior::AkAudioDevice_LoadAllFilePackages(FAkAudioDevice* AkAudioDevice)
{
	return true;
}

bool AkEventBasedIntegrationBehavior::AkAudioDevice_UnloadAllFilePackages(FAkAudioDevice* AkAudioDevice)
{
	return true;
}

void AkEventBasedIntegrationBehavior::AkAudioDevice_LoadAllReferencedBanks(FAkAudioDevice* AkAudioDevice)
{
	// Do nothing
}

void AkEventBasedIntegrationBehavior::AkAudioDevice_SetCurrentAudioCulture(const FString& NewWwiseLanguage)
{
	bool bFullySwitchedLanguage = true;
	int FailedSwitchCount = 0;
	AK::StreamMgr::SetCurrentLanguage(TCHAR_TO_AK(*NewWwiseLanguage));

	for (TObjectIterator<UAkAudioEvent> EventIt; EventIt; ++EventIt)
	{
		if (EventIt->IsLocalized())
		{
			if (!EventIt->SwitchLanguage(NewWwiseLanguage))
			{
				UE_LOG(LogAkAudio, Error, TEXT("Failed to switch language to (%s) for event %s "), *NewWwiseLanguage, *EventIt->GetName());
				bFullySwitchedLanguage = false;
				FailedSwitchCount++;
			}
		}
	}
	
	for (TObjectIterator<UAkAudioBank> AudioBankIt; AudioBankIt; ++AudioBankIt)
	{
		if (AudioBankIt->IsLocalized())
		{
			if (!AudioBankIt->SwitchLanguage(NewWwiseLanguage))
			{
				UE_LOG(LogAkAudio, Error, TEXT("Failed to switch language to (%s) for bank %s "), *NewWwiseLanguage, *AudioBankIt->GetName());
				bFullySwitchedLanguage = false;
				FailedSwitchCount++;
			}
		}
	}

	if (!bFullySwitchedLanguage)
	{
		UE_LOG(LogAkAudio, Error, TEXT("Failed to switch language to (%s) for %d localized assets"), *NewWwiseLanguage, FailedSwitchCount);
	}

	if (GEngine)
	{
		GEngine->ForceGarbageCollection();
	}
}

void AkEventBasedIntegrationBehavior::AkAudioDevice_SetCurrentAudioCultureAsync(FAkAudioDevice* AkAudioDevice, const FString& NewWwiseLanguage, FSetCurrentAudioCultureAction* LatentAction)
{
	FAkAudioDevice::SetCurrentAudioCultureAsyncTask* newTask = new FAkAudioDevice::SetCurrentAudioCultureAsyncTask(NewWwiseLanguage, LatentAction);
	if (newTask->Start())
	{
		AkAudioDevice->AudioCultureAsyncTasks.Add(newTask);
	}
	else
	{
		LatentAction->ActionDone = true;
		delete newTask;
	}
}

void AkEventBasedIntegrationBehavior::AkAudioDevice_SetCurrentAudioCultureAsync(FAkAudioDevice* AkAudioDevice, const FString& NewWwiseLanguage, const FOnSetCurrentAudioCultureCompleted& CompletedCallback)
{
	FAkAudioDevice::SetCurrentAudioCultureAsyncTask* newTask = new FAkAudioDevice::SetCurrentAudioCultureAsyncTask(NewWwiseLanguage, CompletedCallback);
	if (newTask->Start())
	{
		AkAudioDevice->AudioCultureAsyncTasks.Add(newTask);
	}
	else
	{
		CompletedCallback.ExecuteIfBound(false);
		delete newTask;
	}
}

void AkEventBasedIntegrationBehavior::AkAudioDevice_CreateIOHook(FAkAudioDevice* AkAudioDevice)
{
	AkAudioDevice->IOHook = new FAkUnrealIOHook();
}

void AkEventBasedIntegrationBehavior::AkAudioDevice_LoadInitialData(FAkAudioDevice* AkAudioDevice)
{
	AkAudioDevice->LoadInitBank();
	AkAudioDevice->LoadDelayedAssets();
	AkAudioDevice->LoadDelayedMedias();
	AkAudioDevice->BroadcastDelayedSwitches();
}

#if WITH_EDITOR
void AkEventBasedIntegrationBehavior::AkAudioDevice_UnloadAllSoundData(FAkAudioDevice* AkAudioDevice)
{
	if (!AkAudioDevice)
	{
		return;
	}

	AkAudioDevice->StopAllSounds();
	AK::SoundEngine::RenderAudio();
	FPlatformProcess::Sleep(0.1f);

	for (TObjectIterator<UAkMediaAsset> mediaIt; mediaIt; ++mediaIt)
	{
		mediaIt->UnloadMedia();
	}

	for (TObjectIterator<UAkAudioEvent> eventIt; eventIt; ++eventIt)
	{
		eventIt->UnloadBank();
	}

	for (TObjectIterator<UAkAuxBus> auxBusIt; auxBusIt; ++auxBusIt)
	{
		auxBusIt->UnloadBank();
	}

	for (TObjectIterator<UAkAudioBank> audioBankIt; audioBankIt; ++audioBankIt)
	{
		audioBankIt->UnloadBank();
	}

	for (TObjectIterator<UAkInitBank> initBankIt; initBankIt; ++initBankIt)
	{
		initBankIt->UnloadBank();
	}

	AkAudioDevice->InitBank = nullptr;

	// We broke lots of UObject references, we should clean up...
	if (GEngine)
	{
		GEngine->ForceGarbageCollection(true);
	}
}

void AkEventBasedIntegrationBehavior::AkAudioDevice_ReloadAllSoundData(FAkAudioDevice* AkAudioDevice)
{
	AkAudioDevice_UnloadAllSoundData(AkAudioDevice);

	//We need for all media memory to be freed (and UnsetMedia to be called) before we reload media
	auto* MediaMemoryManager = AkMediaMemoryManager::Get();
	if (MediaMemoryManager->HasPendingMediaToRemove())
	{
		OnMediaFreedHandle = MediaMemoryManager->OnAllPendingMediaFreed.AddLambda([this, AkAudioDevice, MediaMemoryManager]
		{
			MediaMemoryManager->OnAllPendingMediaFreed.Remove(this->OnMediaFreedHandle);
			AsyncTask(ENamedThreads::Type::GameThread, [this, AkAudioDevice]
			{
				this->LoadAllSoundData(AkAudioDevice);
			});
		});
	}
	else
	{
		LoadAllSoundData(AkAudioDevice);
	}
}

void AkEventBasedIntegrationBehavior::LoadAllSoundData(FAkAudioDevice* AkAudioDevice)
{
	AkAudioDevice->LoadInitBank();

	for (TObjectIterator<UAkInitBank> initBankIt; initBankIt; ++initBankIt)
	{
		initBankIt->LoadBank();
	}

	for (TObjectIterator<UAkAudioBank> audioBankIt; audioBankIt; ++audioBankIt)
	{
		audioBankIt->LoadBank();
	}

	for (TObjectIterator<UAkAudioEvent> eventIt; eventIt; ++eventIt)
	{
		eventIt->LoadBank();
	}

	for (TObjectIterator<UAkAuxBus> auxBusIt; auxBusIt; ++auxBusIt)
	{
		auxBusIt->LoadBank();
	}

	for (TObjectIterator<UAkMediaAsset> mediaIt; mediaIt; ++mediaIt)
	{
		mediaIt->LoadMedia();
	}

	AkAudioDevice->OnSoundbanksLoaded.Broadcast();
}
#endif

// AkAudioEvent
void AkEventBasedIntegrationBehavior::AkAudioEvent_Load(UAkAudioEvent* AkAudioEvent)
{
	if (AkAudioEvent->IsLocalized())
	{
		if (auto* AudioDevice = FAkAudioDevice::Get())
		{
			AkAudioEvent->LoadLocalizedData(AudioDevice->GetCurrentAudioCulture(), true);
		}
	}
	else
	{
		AkAudioEvent->AssetBaseLoadBank();
	}
}

// AkGameplayStatics
void AkEventBasedIntegrationBehavior::AkGameplayStatics_LoadBank(UAkAudioBank* AkAudioBank, const FString& BankName, FWaitEndBankAction* NewAction)
{
	NewAction->ActionDone = true;
}

void AkEventBasedIntegrationBehavior::AkGameplayStatics_LoadBankAsync(UAkAudioBank* AkAudioBank, const FOnAkBankCallback& BankLoadedCallback)
{
	BankLoadedCallback.ExecuteIfBound(EAkResult::Success);
}

void AkEventBasedIntegrationBehavior::AkGameplayStatics_LoadBankByName(const FString& BankName)
{
	// Do nothing
}

void AkEventBasedIntegrationBehavior::AkGameplayStatics_LoadBanks(const TArray<UAkAudioBank*>& SoundBanks, bool SynchronizeSoundBanks)
{
	// Do nothing
}

void AkEventBasedIntegrationBehavior::AkGameplayStatics_UnloadBank(UAkAudioBank* Bank, const FString& BankName, FWaitEndBankAction* NewAction)
{
	NewAction->ActionDone = true;
}

void AkEventBasedIntegrationBehavior::AkGameplayStatics_UnloadBankAsync(UAkAudioBank* Bank, const FOnAkBankCallback& BankUnloadedCallback)
{
	BankUnloadedCallback.ExecuteIfBound(EAkResult::Success);
}

void AkEventBasedIntegrationBehavior::AkGameplayStatics_UnloadBankByName(const FString& BankName)
{
	// Do nothing
}

// FAkSDKExternalSourceArray
void AkEventBasedIntegrationBehavior::FAkSDKExternalSourceArray_Ctor(FAkSDKExternalSourceArray* Instance, const TArray<FAkExternalSourceInfo>& BlueprintArray)
{
	if (auto* AudioDevice = FAkAudioDevice::Get())
	{
		for (auto& externalSourceInfo : BlueprintArray)
		{
			AkOSChar* OsCharArray = nullptr;
			void* mediaData = nullptr;
			AkUInt32 mediaSize = 0;

			if (externalSourceInfo.ExternalSourceAsset)
			{
				if (externalSourceInfo.IsStreamed)
				{
					auto assetName = externalSourceInfo.ExternalSourceAsset->GetName();
					OsCharArray = (AkOSChar*)FMemory::Malloc((assetName.Len() + 1) * sizeof(AkOSChar));
					FPlatformString::Strcpy(OsCharArray, assetName.Len(), TCHAR_TO_AK(*(assetName)));
					FAkUnrealIOHook::AddExternalMedia(externalSourceInfo.ExternalSourceAsset);
				}
				else
				{
					// TODO: Use C++17 structured binding when available
					auto dataInfo = externalSourceInfo.ExternalSourceAsset->GetExternalSourceData();
					mediaData = dataInfo.Key;
					mediaSize = static_cast<AkUInt32>(dataInfo.Value);
				}
			}
			else
			{
				auto externalFileName = externalSourceInfo.FileName;
				if (FPaths::GetExtension(externalFileName).IsEmpty())
				{
					externalFileName += TEXT(".wem");
				}
				OsCharArray = (AkOSChar*)FMemory::Malloc((externalFileName.Len() + 1) * sizeof(AkOSChar));
				FPlatformString::Strcpy(OsCharArray, externalFileName.Len(), TCHAR_TO_AK(*(externalFileName)));

				auto assetName = FPaths::GetBaseFilename(externalFileName);
				auto assetPath = FPaths::Combine(AkUnrealHelper::GetExternalSourceAssetPackagePath(), FString::Format(TEXT("{0}.{0}"), { *assetName }));

				auto& assetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
				auto assetData = assetRegistryModule.Get().GetAssetByObjectPath(FName(*assetPath));
				if (assetData.IsValid())
				{
					auto* asset = assetData.GetAsset();
					asset->AddToRoot();
					FAkUnrealIOHook::AddExternalMedia(Cast<UAkExternalMediaAsset>(asset));
				}
			}

			if (mediaData && mediaSize)
			{
				Instance->ExternalSourceArray.Emplace(mediaData, mediaSize, FAkAudioDevice::GetIDFromString(externalSourceInfo.ExternalSrcName), (AkCodecID)externalSourceInfo.CodecID);
			}
			else
			{
				Instance->ExternalSourceArray.Emplace(OsCharArray, FAkAudioDevice::GetIDFromString(externalSourceInfo.ExternalSrcName), (AkCodecID)externalSourceInfo.CodecID);
			}
		}
	}
}

