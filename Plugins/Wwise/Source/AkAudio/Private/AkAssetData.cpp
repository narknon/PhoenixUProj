/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2022 Audiokinetic Inc.
*******************************************************************************/

#include "AkAssetData.h"
#include "AkUnrealHelper.h"
#include "AkMediaAsset.h"
#include "Platforms/AkPlatformInfo.h"
#include "IntegrationBehavior/AkIntegrationBehavior.h"
#include "Core/Public/Modules/ModuleManager.h"

#if WITH_EDITOR
#include "TargetPlatform/Public/Interfaces/ITargetPlatform.h"
#include "ISoundBankInfoCache.h"
#endif

void UAkAssetData::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	Data.Serialize(Ar, this);
}

AKRESULT UAkAssetData::LoadAssetData()
{
	auto result = AkIntegrationBehavior::Get()->AkAssetData_LoadBank(this);
	UE_LOG(LogAkAudio, Verbose, TEXT("UAkAssetData::LoadAssetData: Loaded bank for asset %s. Bank Id is %u."), *GetName(), BankID);
	return result;
}

AKRESULT UAkAssetData::UnloadAssetData()
{
	if (BankID == AK_INVALID_BANK_ID)
		return Data.GetBulkDataSize() == 0 ? AK_Success : AK_Fail;

	if (auto AudioDevice = FAkAudioDevice::Get())
	{
		// DO NOT USE ASYNC if bank has media in it. Wwise needs access to the bank pointer in order to stop all playing sounds
		// contained within the bank. Depending on the timing, this can take up to an audio frame to process, so the memory
		// needs to remain available to the SoundEngine during that time. Since we are currently destroying the UObject, we 
		// can't guarantee that the memory will remain available that long.
		// In our case, though, the SoundBank does NOT contain media, so it is safe to unload the bank in a "fire and forget"
		// fashion.
		AudioDevice->UnloadBankFromMemoryAsync(BankID, RawData, [](AkUInt32 in_bankID, const void* in_pInMemoryBankPtr, AKRESULT in_eLoadResult, void* in_pCookie) {}, nullptr);
	}

	BankID = AK_INVALID_BANK_ID;
	RawData = nullptr;
	return AK_Success;
}

#if WITH_EDITOR
void UAkAssetDataWithMedia::FillTempMediaList()
{
	TempMediaList.Empty();

	for (auto& media : MediaList)
	{
		TempMediaList.Emplace(media);
	}
}

void UAkAssetDataWithMedia::FillFinalMediaList()
{
	check(IsInGameThread());

	MediaList.Empty();

	for (auto& tempMedia : TempMediaList)
	{
		MediaList.Add(tempMedia.LoadSynchronous());
	}
}

void UAkAssetDataWithMedia::GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& MediaListArray) const
{
	Super::GetMediaList(MediaListArray);

	for (auto& media : MediaList)
	{
		MediaListArray.AddUnique(media);
	}
}
#endif

void UAkAssetPlatformData::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

#if WITH_EDITORONLY_DATA
	if (!Ar.IsFilterEditorOnly())
	{
		Ar << AssetDataPerPlatform;
		return;
	}

	if (Ar.IsSaving() && !Ar.CookingTarget()->IsServerOnly() && AkUnrealHelper::IsUsingEventBased())
	{
		TArray<FString> AvailableWwisePlatforms;
		AssetDataPerPlatform.GenerateKeyArray(AvailableWwisePlatforms);
		UAkPlatformInfo* CurrentPlatformInfo = UAkPlatformInfo::GetAkPlatformInfo(Ar.CookingTarget()->IniPlatformName());
		FString WwisePlatformName;
		if (LIKELY(CurrentPlatformInfo))
		{
			WwisePlatformName = CurrentPlatformInfo->GetWwiseBankPlatformName(AvailableWwisePlatforms);
		}
		else
		{
			WwisePlatformName = Ar.CookingTarget()->IniPlatformName();
		}
		const auto CurrentMediaData = AssetDataPerPlatform.Find(WwisePlatformName);
		CurrentAssetData = CurrentMediaData ? *CurrentMediaData : nullptr;
		UE_CLOG(!CurrentAssetData, LogAkAudio, Warning, TEXT("UAkAssetPlatformData::Serialize: Cound not find platform %s asset data for asset %s. Asset will not be available in packaged game."), *WwisePlatformName , *GetOutermost()->GetName());
	}
#endif

	Ar << CurrentAssetData;
}

void UAkAssetPlatformData::GetPreloadDependencies(TArray<UObject*>& OutDeps)
{
	OutDeps.Add(CurrentAssetData);
}

#if WITH_EDITOR
void UAkAssetPlatformData::Reset()
{
	AssetDataPerPlatform.Reset();
}

bool UAkAssetPlatformData::NeedsRebuild(const TSet<FString>& PlatformsToBuild, const FString& Language, const FGuid& ID, const ISoundBankInfoCache* SoundBankInfoCache) const
{
	TSet<FString> avaiablePlatforms;

	for (auto& entry : AssetDataPerPlatform)
	{
		avaiablePlatforms.Add(entry.Key);

		if (PlatformsToBuild.Contains(entry.Key))
		{
			if (!SoundBankInfoCache->IsSoundBankUpToUpdate(ID, entry.Key, Language, entry.Value->CachedHash))
			{
				return true;
			}
		}
	}

	if (!avaiablePlatforms.Includes(PlatformsToBuild))
	{
		return true;
	}

	return false;
}

void UAkAssetPlatformData::GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& MediaList) const
{
	for (auto& entry : AssetDataPerPlatform)
	{
		entry.Value->GetMediaList(MediaList);
	}
}
#endif


bool UAkAssetDataSwitchContainerData::IsMediaReady()
{
	if (!AkMediaAssetHelpers::IsMediaReady(MediaList))
	{
		return false;
	}

	for (UAkAssetDataSwitchContainerData* ChildContainer : Children)
	{
		if (!ChildContainer->IsMediaReady())
		{
			return false;
		}
	}
	return true;
}

bool UAkAssetDataSwitchContainerData::IsReadyForAsyncPostLoad() const
{
	for (auto child : Children)
	{
		if (!child->IsReadyForAsyncPostLoad())
		{
			return false;
		}
	}

	for (auto entry : MediaList)
	{
		if (!entry->IsReadyForAsyncPostLoad())
		{
			return false;
		}
	}

	return true;
}

#if WITH_EDITOR
void UAkAssetDataSwitchContainerData::FillTempMediaList()
{
	TempMediaList.Empty();

	for (auto entry : MediaList)
	{
		TempMediaList.Emplace(entry);
	}

	for (auto child : Children)
	{
		child->FillTempMediaList();
	}
}

void UAkAssetDataSwitchContainerData::FillFinalMediaList()
{
	MediaList.Empty();

	for (auto& tempMedia : TempMediaList)
	{
		MediaList.Add(tempMedia.LoadSynchronous());
	}

	for (auto child : Children)
	{
		child->FillFinalMediaList();
	}
}

void UAkAssetDataSwitchContainerData::GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& mediaList) const
{
	internalGetMediaList(this, mediaList);
}

void UAkAssetDataSwitchContainerData::internalGetMediaList(const UAkAssetDataSwitchContainerData* data, TArray<TSoftObjectPtr<UAkMediaAsset>>& mediaList) const
{
	for (auto& media : data->MediaList)
	{
		mediaList.AddUnique(media);
	}

	for (auto* child : data->Children)
	{
		internalGetMediaList(child, mediaList);
	}
}
#endif

void UAkAssetDataSwitchContainer::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}
	
	if (BankLanguage != TEXT("SFX"))
	{
		if (!FModuleManager::Get().IsModuleLoaded(TEXT("AkAudio")))
		{
			// Can do nothing if module not loaded, SoundEngine Init
			// will call SetAudioCulture, which will call LoadSwitchContainers
			return;
		}

		if (auto AudioDevice = FAkAudioDevice::Get())
		{
			if (BankLanguage != AudioDevice->GetCurrentAudioCulture())
			{
				return;
			}
		}
	}

#if WITH_EDITOR
	//Only load editor platform switch containers in editor
	if (!AssetPlatform.IsEmpty())
	{
		UAkPlatformInfo* CurrentPlatformInfo = UAkPlatformInfo::GetAkPlatformInfo(FPlatformProperties::IniPlatformName());
		if (CurrentPlatformInfo && !CurrentPlatformInfo->IsCurrentWwisePlatform(AssetPlatform))
		{
			return;
		}

		if (!CurrentPlatformInfo && AssetPlatform != FPlatformProperties::IniPlatformName())
		{
			return;
		}
	}
	else
	{
		UE_LOG(LogAkAudio, Warning, TEXT("UAkAssetDataSwitchContainer::Serialize: Event data %s in %s is not up to date. Please regenerate sound data."), *GetName(), *GetPackage()->GetFName().ToString());
	}
#endif
	LoadSwitchContainers();
}

bool UAkAssetDataSwitchContainer::IsReadyForAsyncPostLoad() const
{
	for (auto* switchContainer : SwitchContainers)
	{
		if (!switchContainer->IsReadyForAsyncPostLoad())
		{
			return false;
		}
	}

	return true;
}

void UAkAssetDataSwitchContainer::LoadSwitchContainers()
{
	LoadSwitchContainer(SwitchContainers);
}

void UAkAssetDataSwitchContainer::LoadSwitchContainer(const TArray<UAkAssetDataSwitchContainerData*>& SwitchContainersToLoad)
{
	for (auto* Container : SwitchContainersToLoad)
	{
		LoadSwitchContainer(Container);
	}
}

void UAkAssetDataSwitchContainer::LoadSwitchContainer(UAkAssetDataSwitchContainerData* SwitchContainer)
{
	if (SwitchContainer)
	{
		//Check the group value is loaded in memory before attempting to access the container's children or load its media
		bool bIsGroupValueValid = IsValid(SwitchContainer->GroupValue.Get());
		//If the group value is not set, we are dealing with a generic path in a music container.
		//In this case we want to continue stepping in children and load any media associated with the generic path.
		bool bIsGroupValueUnset = SwitchContainer->GroupValue.IsNull();
		if (bIsGroupValueValid || bIsGroupValueUnset)
		{
			for (UAkMediaAsset* media : SwitchContainer->MediaList)
			{
				if (IsValid(media))
				{
					UE_LOG(LogAkAudio, Verbose, TEXT("UAkAssetDataSwitchContainer::LoadSwitchContainer: Loading media %u"), media->Id);

					media->LoadMedia(true);
				}
			}

			LoadSwitchContainer(SwitchContainer->Children);
		}
		else
		{
			FString FullName = SwitchContainer->GroupValue.GetAssetName();

			int32 Position;
			if (FullName.FindLastChar('-', Position))
			{
				FString ValueName = FullName.RightChop(Position+1);
				uint32 SwitchID = FAkAudioDevice::GetIDFromString(ValueName);
				FAkAudioDevice::GetOnSwitchValueLoaded(SwitchID).AddUObject(this, &UAkAssetDataSwitchContainer::OnSwitchValueLoaded);
				UAkAssetDataSwitchContainerData*& PendingSwitchAssetData = PendingSwitchLoads.Add(SwitchID, SwitchContainer);
			}
		}
	}
}

void UAkAssetDataSwitchContainer::OnSwitchValueLoaded(UAkGroupValue* NewGroupValue)
{
	if (NewGroupValue && NewGroupValue->IsValidLowLevelFast())
	{
		UAkAssetDataSwitchContainerData* PendingAssetData;
		if (PendingSwitchLoads.RemoveAndCopyValue(NewGroupValue->ShortID, PendingAssetData))
		{
			LoadSwitchContainer(PendingAssetData);
		}

		FAkAudioDevice::GetOnSwitchValueLoaded(NewGroupValue->ShortID).RemoveAll(this);
	}
}

void UAkAssetDataSwitchContainer::BeginDestroy()
{
	for (auto Pair : PendingSwitchLoads)
	{
		uint32 SwitchValueID = Pair.Key;
		FAkAudioDevice::GetOnSwitchValueLoaded(SwitchValueID).RemoveAll(this);
	}
	PendingSwitchLoads.Reset();
	Super::BeginDestroy();
}

void UAkAssetDataSwitchContainer::UnloadSwitchContainers()
{
	UnloadSwitchContainerMedia(SwitchContainers);
}

void UAkAssetDataSwitchContainer::UnloadSwitchContainerMedia(const TArray<UAkAssetDataSwitchContainerData*>& switchContainers)
{
	for (auto* container : switchContainers)
	{
		UnloadSwitchContainerMedia(container);
	}
}

void UAkAssetDataSwitchContainer::UnloadSwitchContainerMedia(UAkAssetDataSwitchContainerData* switchContainer)
{
	if (switchContainer)
	{
		for (UAkMediaAsset* media : switchContainer->MediaList)
		{
			if (IsValid(media))
			{
				UE_LOG(LogAkAudio, VeryVerbose, TEXT("Unloading media %s in switch container %s."), *media->GetName(), *GetName());
				media->UnloadMedia();
			}
		}

		UnloadSwitchContainerMedia(switchContainer->Children);
	}
}

bool UAkAssetDataSwitchContainer::IsMediaReady()
{
	if (!AkMediaAssetHelpers::IsMediaReady(MediaList))
	{
		return false;
	}
	for (UAkAssetDataSwitchContainerData* SwitchContainer: SwitchContainers)
	{
		if (!SwitchContainer->IsMediaReady())
		{
			return false;
		}
	}
	return true;
}

void UAkAssetDataSwitchContainer::GetPreloadDependencies(TArray<UObject*>& OutDeps)
{
	Super::GetPreloadDependencies(OutDeps);

	for (auto* container : SwitchContainers)
	{
		if (container != nullptr)
		{
			OutDeps.Add(container);
		}
	}
}

#if WITH_EDITOR
void UAkAssetDataSwitchContainer::FillTempMediaList()
{
	Super::FillTempMediaList();

	for (auto* switchContainer : SwitchContainers)
	{
		switchContainer->FillTempMediaList();
	}
}

void UAkAssetDataSwitchContainer::FillFinalMediaList()
{
	Super::FillFinalMediaList();

	for (auto* switchContainer : SwitchContainers)
	{
		switchContainer->FillFinalMediaList();
	}
}

void UAkAssetDataSwitchContainer::GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& mediaList) const
{
	Super::GetMediaList(mediaList);

	for (auto* switchContainer : SwitchContainers)
	{
		switchContainer->GetMediaList(mediaList);
	}
}
#endif
