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

#include "AkMediaAsset.h"

#include "AkAudioDevice.h"
#include "AkUnrealHelper.h"
#include "AkUnrealIOHook.h"
#include "AkMediaMemoryManager.h"
#include "HAL/PlatformProperties.h"
#include "Core/Public/Modules/ModuleManager.h"
#include "Misc/ScopeExit.h"
#include "Platforms/AkPlatformInfo.h"

#if WITH_EDITOR
#include "Interfaces/ITargetPlatform.h"
#endif

FAkMediaDataChunk::FAkMediaDataChunk() { }

#if WITH_EDITOR
FAkMediaDataChunk::FAkMediaDataChunk(IFileHandle* FileHandle, int64 BytesToRead, uint32 BulkDataFlags, FCriticalSection* DataWriteLock, bool IsPrefetch)
	: IsPrefetch(IsPrefetch)
{
	FScopeLock DataLock(DataWriteLock);
	Data.SetBulkDataFlags(BulkDataFlags);
	Data.Lock(EBulkDataLockFlags::LOCK_READ_WRITE);
	FileHandle->Read(reinterpret_cast<uint8*>(Data.Realloc(BytesToRead)), BytesToRead);
	Data.Unlock();
}
#endif

void FAkMediaDataChunk::Serialize(FArchive& Ar, UObject* Owner)
{
	Ar << IsPrefetch;
	Data.Serialize(Ar, Owner);
}

uint32 UAkMediaAssetData::GetParentMediaId() const
{
	UAkMediaAsset* ParentMediaAsset = Cast<UAkMediaAsset>(GetOuter());
	return ParentMediaAsset ? ParentMediaAsset->Id : 0;
}

FString UAkMediaAssetData::GetParentMediaName() const
{
	UAkMediaAsset* ParentMediaAsset = Cast<UAkMediaAsset>(GetOuter());
	return ParentMediaAsset ? ParentMediaAsset->MediaName : "Unknown";
}

UAkMediaAssetData::LoadState UAkMediaAssetData::GetLoadState() const
{
	return State;
}

auto UAkMediaAssetData::GetPreloadDependencies(TArray<UObject*>& OutDeps) -> void
{
	Super::GetPreloadDependencies(OutDeps);
	OutDeps.Add(GetOuter());
}

bool UAkMediaAssetData::IsCurrentWwisePlatform(const FString& AssetDataPlatform)
{
	static UAkPlatformInfo* CurrentPlatformInfo = nullptr;
	if (!CurrentPlatformInfo)
	{
		CurrentPlatformInfo = UAkPlatformInfo::GetAkPlatformInfo(FPlatformProperties::IniPlatformName());
	}

	if(LIKELY(CurrentPlatformInfo))
	{
		return CurrentPlatformInfo->IsCurrentWwisePlatform(AssetDataPlatform);
	}

	return AssetDataPlatform == FPlatformProperties::IniPlatformName();
}


void UAkMediaAssetData::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::Serialize: Media is (%s - %u)"), *GetParentMediaName(),  GetParentMediaId());

	int32 numChunks = DataChunks.Num();
	Ar << numChunks;

	if (Ar.IsLoading())
	{
		DataChunks.Empty();
		for (int32 i = 0; i < numChunks; ++i)
		{
			DataChunks.Add(new FAkMediaDataChunk());
		}
	}

	for (int32 i = 0; i < numChunks; ++i)
	{
		DataChunks[i].Serialize(Ar, this);
	}

	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}

#if WITH_EDITOR
	if (AssetPlatform.IsEmpty())
	{
		UE_LOG(LogAkAudio, Warning, TEXT("UAkMediaAssetData::Serialize: Media data %s in %s is not up to date. Please regenerate sound data."), *GetName(), *GetPackage()->GetFName().ToString());
	}
#endif

	if (Ar.IsLoading())
	{
		UE_LOG(LogAkAudio, VeryVerbose, TEXT("UAkMediaAssetData::Serialize: Checking if NeedsAutoloading."));
		if (NeedsAutoLoading())
		{
			UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::Serialize: Loading media asset data (%s - %u)"), *GetParentMediaName(),  GetParentMediaId());
			LoadMediaAssetData(true);
			FExternalReadCallback ExternalReadCallback = [this](double RemainingTime)
			{
				return this->ExternalReadCallback((RemainingTime));
			};
			Ar.AttachExternalReadDependency(ExternalReadCallback);
		}
	}
}

bool UAkMediaAssetData::ExternalReadCallback(double RemainingTime)
{
#if !WITH_EDITOR
	if (LoadingRequest)
	{
		if (RemainingTime < 0.0 && !LoadingRequest->PollCompletion())
		{
			return false;
		}
		else if (RemainingTime >= 0.0 && !LoadingRequest->WaitCompletion(RemainingTime))
		{
			return false;
		}
		return true;
	}
#endif
	return State == LoadState::Loaded || State == LoadState::Error;
}

bool UAkMediaAssetData::IsReadyForAsyncPostLoad() const
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return true;
	}

	if (!FModuleManager::Get().IsModuleLoaded(TEXT("AkAudio")))
	{
		return true;
	}

	UE_LOG(LogAkAudio, VeryVerbose, TEXT("UAkMediaAssetData::IsReadyForAsyncPostLoad: Checking if NeedsAutoloading."));
	bool bNeedsAutoloading = NeedsAutoLoading();
	if (bNeedsAutoloading && State == LoadState::Unloaded)
	{
		UE_LOG(LogAkAudio, Error, TEXT("UAkMediaAssetData::IsReadyForAsyncPostLoad: NeedsAutoLoading returned true, but loadstate is unloaded. Media name : %s - %u"), *GetParentMediaName(),  GetParentMediaId());
		return false;
	}

	if (bNeedsAutoloading )
	{
		return State == LoadState::Loaded || State == LoadState::Error;
	}

	return true;
}

FString UAkMediaAssetData::StateToString() const
{
	switch (State)
	{
	case LoadState::Unloaded:
		return FString("Unloaded");
	case LoadState::Loading:
		return FString("Loading");
	case LoadState::Loaded:
		return FString("Loaded");
	case LoadState::Error:
	default:
		return FString("Error");
	}
}

void UAkMediaAssetData::LoadMediaAssetData(bool LoadAsync)
{
	if (IsRunningCommandlet() || HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}

	if (Language != "SFX")
	{
		UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::LoadMediaAssetData: Loading localized media data for media asset %s - %u for language %s."), *GetParentMediaName(), GetParentMediaId(), *Language);
	}

	if (State == LoadState::Loading)
	{
		UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::LoadMediaAssetData: Already have a loading request for Id %u. State is %s."), GetParentMediaId(), *StateToString());
		return;
	}

	auto* MediaMemoryManager = AkMediaMemoryManager::Get();
	UAkMediaAsset* ParentMediaAsset = Cast<UAkMediaAsset>(GetOuter());
	if (DataChunks.Num() > 0 && ParentMediaAsset && MediaMemoryManager)
	{
		int64 MediaSize = DataChunks[0].Data.GetBulkDataSize();
#if !WITH_EDITOR
		BulkDataRequestCompletedCallback LoadAsyncCompleted = [this](bool bWasCancelled, ReadRequestArgumentType* ReadRequest) 
		{
			BulkDataStreamingRequestCompleted(bWasCancelled, ReadRequest);
		};

		if (DataChunks[0].Data.CanLoadFromDisk() && LoadAsync)
		{
			uint8* TempReadMediaMemory;
			const bool bMediaAlreadyInMemory = MediaMemoryManager->RequestMediaMemory(ParentMediaAsset->MediaName, ParentMediaAsset->Id, MediaSize, UseDeviceMemory, TempReadMediaMemory);
			if (!bMediaAlreadyInMemory)
			{
				State = LoadState::Loading;
				UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::Load: Creating streaming request for %u"), ParentMediaAsset->Id);
				LoadingRequest = DataChunks[0].Data.CreateStreamingRequest(EAsyncIOPriorityAndFlags::AIOP_High, &LoadAsyncCompleted, TempReadMediaMemory);
			}
			else
			{
				UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::Load: Media already loaded for %u"), GetParentMediaId());
				State = LoadState::Loaded;
				LoadedMediaData = TempReadMediaMemory;
			}
		}
		else
#endif
		{
			bool bMediaAlreadyInMemory = MediaMemoryManager->RequestMediaMemory(ParentMediaAsset->MediaName, GetParentMediaId(), MediaSize, UseDeviceMemory, LoadedMediaData);
			State = LoadState::Loaded;
			if (!bMediaAlreadyInMemory)
			{
				auto BulkMediaDataSize = DataChunks[0].Data.GetBulkDataSize();
				DataChunks[0].Data.GetCopy((void**)&LoadedMediaData, false);

				MediaMemoryManager->SetMedia(ParentMediaAsset->MediaName, GetParentMediaId(),LoadedMediaData, MediaSize);
				ParentMediaAsset->bIsMediaSet = true;
			}
		}
	}
	else
	{
		UE_LOG(LogAkAudio, Error, TEXT("Skipping media load. DataChunks.Num()=%u; LoadedMediaData=%u; Parent=%u; MediaMemoryManager=%u"), DataChunks.Num(), LoadedMediaData, ParentMediaAsset, MediaMemoryManager);
		State = LoadState::Error;
	}
}

#if !WITH_EDITOR
void UAkMediaAssetData::BulkDataStreamingRequestCompleted(bool bWasCancelled, ReadRequestArgumentType* ReadRequest)
{
	if (bWasCancelled)
	{
		auto* MediaMemoryManager = AkMediaMemoryManager::Get();
		auto MediaID = GetParentMediaId();
		if (MediaMemoryManager && MediaID != AK_INVALID_UNIQUE_ID)
		{
			MediaMemoryManager->ReleaseMediaMemory(MediaID);
		}
		State = LoadState::Error;
		UE_LOG(LogAkAudio, Error, TEXT("Bulk data streaming request for Media ID %u was cancelled. Media will be unavailable."), GetParentMediaId());
	}
	else
	{
		LoadedMediaData = ReadRequest->GetReadResults();
		State = LoadState::Loaded;
		UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::LoadMediaAssetData: Finished loading Id %u. State is %s"), GetParentMediaId(), *StateToString());

		auto* MediaMemoryManager = AkMediaMemoryManager::Get();
		if (MediaMemoryManager)
		{
			int64 MediaSize = DataChunks[0].Data.GetBulkDataSize();
			MediaMemoryManager->SetMedia(GetParentMediaName(), GetParentMediaId(), LoadedMediaData, MediaSize);
			if (UAkMediaAsset* ParentMediaAsset = Cast<UAkMediaAsset>(GetOuter()))
			{
				ParentMediaAsset->bIsMediaSet = true;
			}
		}
		else
		{
			UE_LOG(LogAkAudio, Error, TEXT("Could not get Media MemoryManager. Media %s - %u will not be set"), *GetParentMediaName(), GetParentMediaId());
		}

	}
}
#endif

void UAkMediaAssetData::UnloadMediaAssetData()
{
	if (IsRunningCommandlet() || HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}
	
#if !WITH_EDITOR
	if (LoadingRequest)
	{
		if (!LoadingRequest->PollCompletion())
		{
			UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::UnloadMediaAssetData: We have a pending loading request for media asset %s - %u. Cancelling it!"), *GetParentMediaName(), GetParentMediaId(), *Language);
			LoadingRequest->Cancel();
			LoadingRequest->WaitCompletion();
		}
		delete LoadingRequest; LoadingRequest = nullptr;
	}
#endif

	AkMediaMemoryManager* MediaMemoryManager = AkMediaMemoryManager::Get();
	UAkMediaAsset* ParentMediaAsset = Cast<UAkMediaAsset>(GetOuter());
	uint32 MediaID = ParentMediaAsset ? ParentMediaAsset->Id : AK_INVALID_UNIQUE_ID;
	if (ParentMediaAsset)
	{
		if (ParentMediaAsset->bIsMediaSet)
		{
			if (MediaMemoryManager && MediaID != AK_INVALID_UNIQUE_ID && ParentMediaAsset->GetMediaAssetData() == this)
			{
				UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::UnloadMediaAssetData: Unsetting media %u. Media Asset data is at %p"), MediaID, this);
				MediaMemoryManager->ReleaseMediaMemory(MediaID);
				LoadedMediaData = nullptr;
				State = LoadState::Unloaded;
			}
			else
			{
				UE_LOG(LogAkAudio, Error, TEXT("UAkMediaAssetData::UnloadMediaAssetData: Could not unload media %s."), *GetOutermost()->GetName());
				State = LoadState::Error;
				LoadedMediaData = nullptr;
			}
		}
	}
	else if (LoadedMediaData != nullptr)
	{
		if (MediaMemoryManager && MediaID != AK_INVALID_UNIQUE_ID )
		{
			UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::UnloadMediaAssetData: MediaAssetData %s has no valid parent, but memory was still set. Unsetting media %u. Media Asset data is at %p"), 
				*GetOutermost()->GetName(), MediaID, this);
			MediaMemoryManager->ReleaseMediaMemory(MediaID);
		}
		State = LoadState::Error;
		LoadedMediaData = nullptr;
	}
}

void UAkMediaAssetData::BeginDestroy()
{
	if (IsStreamed)
	{
		FAkUnrealIOHook::RemoveStreamingMedia(Cast<UAkMediaAsset>(GetOuter()));
	}

	UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAssetData::BeginDestroy"));
	UnloadMediaAssetData();
	Super::BeginDestroy();
}

bool UAkMediaAssetData::IsReadyForFinishDestroy()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return Super::IsReadyForFinishDestroy();
	}

#if !WITH_EDITOR
	if (LoadingRequest)
	{
		if (LoadingRequest->WaitCompletion(0.01f))
		{
			delete LoadingRequest; LoadingRequest = nullptr;
		}
		else
		{
			return false;
		}
	}
#endif
	return Super::IsReadyForFinishDestroy();
}


bool UAkMediaAssetData::NeedsAutoLoading() const
{
	if (IsRunningCommandlet())
	{
		return false;
	}

	if (!IsCurrentWwisePlatform(AssetPlatform))
	{
		const FString MediaName = GetParentMediaName();
		const uint32 MediaId = GetParentMediaId();
		const FString IniName = FPlatformProperties::IniPlatformName();
		#if !WITH_EDITORONLY_DATA
			UE_LOG(LogAkAudio, Error, TEXT("UAkMediaAssetData::NeedsAutoLoading: Platform %s for media asset data appears to be invalid for current platform (%s). Media name:  %s - %u"), *AssetPlatform, *IniName, *MediaName, MediaId);
		#else
			UE_LOG(LogAkAudio, VeryVerbose, TEXT("UAkMediaAssetData::NeedsAutoLoading: Not loading asset data for platform %s as it is not the current platform %s. Media name:  %s- %u"), *AssetPlatform, *IniName, *MediaName, MediaId);
		#endif
		return false;
	}

	if (DataChunks.Num() > 0)
	{
		if (!IsStreamed || (IsStreamed && DataChunks.Num() > 1 && DataChunks[0].IsPrefetch))
		{
			bool bIsSFX = Language == TEXT("SFX");
			bool bIsCurrentAudioCulture = false;

			
			FString CurrentAudioCulture = TEXT("");
			if (!bIsSFX)
			{
				if (!FModuleManager::Get().IsModuleLoaded(TEXT("AkAudio")))
				{
					// Module is not loaded, but localized media will be loaded by call to
					// SetCurrentAudioCulture at SoundEngine Init, we can simply return false here
					return false;
				}

				if (auto AkAudioDevice = FAkAudioDevice::Get())
				{
					CurrentAudioCulture = AkAudioDevice->GetCurrentAudioCulture();
					bIsCurrentAudioCulture = Language == CurrentAudioCulture;
				}
			}

			UAkMediaAsset* ParentMediaAsset = Cast<UAkMediaAsset>(GetOuter());
			FString MediaName = GetParentMediaName();
			uint32 MediaId = GetParentMediaId();
			if (!ParentMediaAsset)
			{
				UE_LOG(LogAkAudio, VeryVerbose, TEXT("UAkMediaAssetData::NeedsAutoLoading: Asset data will not be loaded because parent is not valid. Media name:  %s- %u"),
					*MediaName, MediaId);
			}
			if (!bIsSFX && !bIsCurrentAudioCulture)
			{
				UE_LOG(LogAkAudio, VeryVerbose, TEXT("UAkMediaAssetData::NeedsAutoLoading: Asset data will not be loaded because it is not SFX and language does not match current language (%s). Media Language : %s. Media name: %s - %u."), *CurrentAudioCulture, *Language, *MediaName, MediaId);
			}
			if (ParentMediaAsset && (ParentMediaAsset->AutoLoad && (bIsSFX || bIsCurrentAudioCulture)))
			{
				UE_LOG(LogAkAudio, VeryVerbose, TEXT("UAkMediaAssetData::NeedsAutoLoading: Asset needs autoloading. AutoLoad = %d | IsSFX = %d | ISCurrentAudioCulture = %d.  Media name: %s - %u "), ParentMediaAsset->AutoLoad, bIsSFX, bIsCurrentAudioCulture,  *MediaName, MediaId);
				return true;
			}
		}
	}

	return false;
}

void UAkMediaAsset::Serialize(FArchive& Ar)
{
	SerializeHasBeenCalled = true;
	bIsMediaSet = false;
	Super::Serialize(Ar);

	UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::Serialize: Media is (%s - %u). ForceAutoLoad = %d | AutoLoad = %d | LoadFromSerialize = %d"), *MediaName,  Id, ForceAutoLoad, AutoLoad, LoadFromSerialize);

	if (Ar.IsLoading())
	{
		ForceAutoLoad = AutoLoad || LoadFromSerialize;
	}

#if WITH_EDITORONLY_DATA
	if (Ar.IsFilterEditorOnly())
	{
		if (Ar.IsSaving() && !Ar.CookingTarget()->IsServerOnly() && AkUnrealHelper::IsUsingEventBased())
		{
			TArray<FString> AvailableWwisePlatforms;
			MediaAssetDataPerPlatform.GenerateKeyArray(AvailableWwisePlatforms);
			UAkPlatformInfo* CurrentPlatformInfo = UAkPlatformInfo::GetAkPlatformInfo(Ar.CookingTarget()->IniPlatformName());
			FString WwisePlatformName;
			if(LIKELY(CurrentPlatformInfo))
			{
				WwisePlatformName = CurrentPlatformInfo->GetWwiseBankPlatformName(AvailableWwisePlatforms);
			}
			else
			{
				WwisePlatformName = Ar.CookingTarget()->IniPlatformName();
			}
			const auto CurrentMediaData = MediaAssetDataPerPlatform.Find(WwisePlatformName);
			CurrentMediaAssetData = CurrentMediaData ? *CurrentMediaData : nullptr;
			UE_CLOG(!CurrentMediaAssetData, LogAkAudio, Warning, TEXT("UAkMediaAsset::Serialize: Cound not find platform %s asset data for media asset %s. Media will not be available in packaged game."), *WwisePlatformName , *GetOutermost()->GetName());
		}
		Ar << CurrentMediaAssetData;
	}
	else
	{
		Ar << MediaAssetDataPerPlatform;
	}
#else
	Ar << CurrentMediaAssetData;
#endif
}

void UAkMediaAsset::PostLoad()
{
	Super::PostLoad();
	
	if (AutoLoad || ForceAutoLoad)
	{
		UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::PostLoad: Loading media %s - %u"), *MediaName, Id);
		LoadMedia();
	}
}

#if WITH_EDITOR
#include "Async/Async.h"
void UAkMediaAsset::Reset()
{
	UnloadMedia();

	bool bChanged = false;
	if (MediaAssetDataPerPlatform.Num() > 0 || !MediaName.IsEmpty() || CurrentMediaAssetData != nullptr)
	{
		bChanged = true;
	}

	MediaAssetDataPerPlatform.Empty();
	MediaName.Empty();
	CurrentMediaAssetData = nullptr;
	
	if (bChanged)
	{
		AsyncTask(ENamedThreads::GameThread, [this] {
			MarkPackageDirty();
			});
	}
}

UAkMediaAssetData* UAkMediaAsset::FindOrAddMediaAssetData(const FString& Platform)
{
	auto PlatformData = MediaAssetDataPerPlatform.Find(Platform);
	if (PlatformData)
	{
		return *PlatformData;
	}

	auto NewPlatformData = NewObject<UAkMediaAssetData>(this);
	NewPlatformData->Language = this->Language;
	MediaAssetDataPerPlatform.Add(Platform, NewPlatformData);
	return NewPlatformData;
}
#endif

void UAkMediaAsset::LoadMedia(bool bFromSerialize /*= false*/)
{
	UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::LoadMedia: Loading media %s - %u"), *MediaName, Id);

	if (!FModuleManager::Get().IsModuleLoaded(TEXT("AkAudio")))
	{
		UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::LoadMedia: %s - %u: AkAudio module not initialized, delaying media load"), *MediaName, Id);
		FAkAudioDevice::DelayMediaLoad(this);
		return;
	}
	
	if (auto AkAudioDevice = FAkAudioDevice::Get())
	{
		auto CurrentCulture = AkAudioDevice->GetCurrentAudioCulture();
		if (Language != TEXT("SFX") && CurrentCulture != Language)
		{
			UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::LoadMedia: Not calling LoadAndSetMedia because current language could not be determined. Media Name : %s. Media ID : %u. Media language : %s."), *MediaName, Id, *Language);
			return;
		}
	}

	if (UNLIKELY(bFromSerialize && !SerializeHasBeenCalled))
	{
		LoadFromSerialize = true;
	}
	else
	{
		LoadAndSetMedia(true);
	}
}

bool UAkMediaAsset::IsReadyForAsyncPostLoad() const
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return true;
	}
	if (auto MediaAssetData = GetMediaAssetData())
	{
		return MediaAssetData->IsReadyForAsyncPostLoad();
	}

	return true;
}

FAkMediaDataChunk const* UAkMediaAsset::GetStreamedChunk() const
{
	auto MediaAssetData = GetMediaAssetData();
	if (!MediaAssetData || MediaAssetData->DataChunks.Num() <= 0)
	{
		return nullptr;
	}

	if (!MediaAssetData->DataChunks[0].IsPrefetch)
	{
		return &MediaAssetData->DataChunks[0];
	}

	if (MediaAssetData->DataChunks.Num() >= 2)
	{
		return &MediaAssetData->DataChunks[1];
	}

	return nullptr;
}

UAkMediaAssetData::LoadState UAkMediaAsset::GetLoadState() const
{
	if (const UAkMediaAssetData* MediaAssetData = GetMediaAssetData())
	{
		return MediaAssetData->GetLoadState();
	}
	return UAkMediaAssetData::LoadState::Error;
}

FString UAkMediaAsset::GetLoadStateString() const
{
	if (const UAkMediaAssetData* MediaAssetData = GetMediaAssetData())
	{
		return MediaAssetData->StateToString();
	}
	return TEXT("Error");
}

bool UAkMediaAsset::ExternalReadCallback(double RemainingTime)
{
	if (UAkMediaAssetData* MediaAssetData = GetMediaAssetData())
	{
		return MediaAssetData->ExternalReadCallback(RemainingTime);
	}
	return true;
}

void UAkMediaAsset::LoadAndSetMedia(bool bLoadAsync)
{
	auto MediaAssetData = GetMediaAssetData();
	if (!MediaAssetData || MediaAssetData->DataChunks.Num() <= 0)
	{
#if WITH_EDITOR
		ForceAutoLoad = true;
#endif
		return;
	}

	UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::LoadAndSetMedia: Id is %u. Name is %s. State is %s."), Id, *MediaName, *MediaAssetData->StateToString());
	for (auto& DataChunk : MediaAssetData->DataChunks)
	{
		if (MediaAssetData->IsStreamed && !DataChunk.IsPrefetch)
		{
			FAkUnrealIOHook::AddStreamingMedia(this);
			UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::LoadAndSetMedia: Added streaming media."));
		}
	}

	if (MediaAssetData->IsStreamed && !MediaAssetData->DataChunks[0].IsPrefetch)
	{
		// This media is streaming with no prefetch. Nothing else to do here.
		return;
	}

#if !WITH_EDITOR
	if (MediaAssetData->DataChunks[0].Data.GetBulkDataSize() <= 0)
	{
		return;
	}
#endif

	if (MediaAssetData->IsLoaded())
	{
		UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::LoadAndSetMedia: Media already loaded, nothing to do. Media is %s - %u. State is %s."), *MediaName, Id,  *MediaAssetData->StateToString());
	}
	else
	{
		UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::LoadAndSetMedia: Loading media asset data. Media is %s - %u. State is %s."),*MediaName,  Id, *MediaAssetData->StateToString());
		MediaAssetData->LoadMediaAssetData(bLoadAsync);
	}
}


void UAkMediaAsset::UnloadMedia()
{
	UE_LOG(LogAkAudio, Verbose, TEXT("UAkMediaAsset::UnloadMedia: Id is %u. Name is %s."), Id, *MediaName);
	auto MediaAssetData = GetMediaAssetData();
	if (!MediaAssetData)
	{
		return;
	}

	if (MediaAssetData->IsStreamed)
	{
		FAkUnrealIOHook::RemoveStreamingMedia(this);
	}
	if (bIsMediaSet)
	{
		MediaAssetData->UnloadMediaAssetData();
	}
	bIsMediaSet = false;
}

UAkMediaAssetData* UAkMediaAsset::GetMediaAssetData() const
{
#if !WITH_EDITORONLY_DATA
	return CurrentMediaAssetData;
#else
	const FString RunningPlatformName(FPlatformProperties::IniPlatformName());
	if (auto PlatformMediaData = MediaAssetDataPerPlatform.Find(RunningPlatformName))
	{
		return *PlatformMediaData;
	}

	return nullptr;
#endif
}

UAkExternalMediaAsset::UAkExternalMediaAsset()
{
	AutoLoad = false;
}

void UAkExternalMediaAsset::Serialize(FArchive& Ar)
{
	if (Id == AK_INVALID_UNIQUE_ID)
	{
		Id = FAkAudioDevice::GetIDFromString(GetName());
	}
	Super::Serialize(Ar);
}

TTuple<void*, int64> UAkExternalMediaAsset::GetExternalSourceData()
{
	auto MediaAssetData = GetMediaAssetData();

	if (MediaAssetData && MediaAssetData->DataChunks.Num() > 0)
	{
		LoadAndSetMedia(false);
		auto result = MakeTuple(static_cast<void*>(MediaAssetData->LoadedMediaData), MediaAssetData->DataChunks[0].Data.GetBulkDataSize());
		return result;
	}

	return {};
}

void UAkExternalMediaAsset::AddPlayingID(uint32 EventID, uint32 PlayingID)
{
	auto& PlayingIDArray = ActiveEventToPlayingIDMap.FindOrAdd(EventID);
	PlayingIDArray.Add(PlayingID);
}

bool UAkExternalMediaAsset::HasActivePlayingIDs()
{
	if (auto* AudioDevice = FAkAudioDevice::Get())
	{
		for (auto ActiveEventToPlayingIDs : ActiveEventToPlayingIDMap)
		{
			uint32 EventID = ActiveEventToPlayingIDs.Key;
			for (auto PlayingID : ActiveEventToPlayingIDs.Value)
			{
				if (AudioDevice->IsPlayingIDActive(EventID, PlayingID))
				{
					return true;
				}
			}
		}
	}

	return false;
}

void UAkExternalMediaAsset::BeginDestroy()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		Super::BeginDestroy();
		return;
	}
	if (auto* AudioDevice = FAkAudioDevice::Get())
	{
		for (auto ActiveEventToPlayingIDs : ActiveEventToPlayingIDMap)
		{
			uint32 EventID = ActiveEventToPlayingIDs.Key;
			for (auto PlayingID : ActiveEventToPlayingIDs.Value)
			{
				if (AudioDevice->IsPlayingIDActive(EventID, PlayingID))
				{
					UE_LOG(LogAkAudio, Warning, TEXT("Stopping PlayingID %u because media file %s is being unloaded."), PlayingID, *GetName());
					AudioDevice->StopPlayingID(PlayingID);
				}
			}
		}
	}
	Super::BeginDestroy();
}

bool UAkExternalMediaAsset::IsReadyForFinishDestroy()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return Super::IsReadyForFinishDestroy();
	}
	if (HasActivePlayingIDs())
	{
		if (auto* AudioDevice = FAkAudioDevice::Get())
		{
			AudioDevice->Update(0.0);
			return false;
		}
	}
	return Super::IsReadyForFinishDestroy();
}

void UAkExternalMediaAsset::PinInGarbageCollector(uint32 PlayingID)
{
	if (TimesPinnedToGC.Increment() == 1)
	{
		AddToRoot();
	}
	
	if (auto* AudioDevice = FAkAudioDevice::Get())
	{
		AudioDevice->AddToPinnedMediasMap(PlayingID, this);
	}
}

void UAkExternalMediaAsset::UnpinFromGarbageCollector(uint32 PlayingID)
{
	if (TimesPinnedToGC.Decrement() == 0)
	{
		RemoveFromRoot();
	}
}

bool AkMediaAssetHelpers::IsMediaReady(const TArray<UAkMediaAsset*>& InMediaList)
{
	FString CurrentAudioCulture = "Unknown";

	if (auto* AudioDevice = FAkAudioDevice::Get())
	{
		CurrentAudioCulture = AudioDevice->GetCurrentAudioCulture();
	}

	for (UAkMediaAsset* MediaAsset : InMediaList)
	{
		if (MediaAsset->IsValidLowLevel())
		{
			//Any media that is meant to be in memory should either be loaded or loading
			switch (MediaAsset->GetLoadState())
			{
			case UAkMediaAssetData::LoadState::Loading:
				return false;
				break;
			case UAkMediaAssetData::LoadState::Error:
				UE_LOG(LogAkAudio, Warning, TEXT("AkMediaAssetHelpers::IsMediaReady : Media failed to load or could not obtain LoadState for media asset %s. Media language is %s."), *MediaAsset->MediaName, *MediaAsset->Language);
			case UAkMediaAssetData::LoadState::Unloaded:
			case UAkMediaAssetData::LoadState::Loaded:
			default:
				continue;
			}
		}
	}
	return true;
}
