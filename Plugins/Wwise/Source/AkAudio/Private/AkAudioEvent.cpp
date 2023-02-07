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


/*=============================================================================
	AkEvent.cpp:
=============================================================================*/

#include "AkAudioEvent.h"
#include "AkAudioBank.h"
#include "AkAudioDevice.h"
#include "AkGroupValue.h"
#include "AkMediaAsset.h"
#include "AkAssetData.h"
#include "AkUnrealHelper.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "HAL/PlatformProperties.h"
#include "IntegrationBehavior/AkIntegrationBehavior.h"

#if WITH_EDITOR
#include "AssetTools/Public/AssetToolsModule.h"
#include "UnrealEd/Public/ObjectTools.h"
#endif


float UAkAudioEvent::GetMaxAttenuationRadius() const
{
	if (auto* EventData = Cast<UAkAudioEventData>(GetAssetData()))
	{
		return EventData->MaxAttenuationRadius;
	}

	return 0.f;
}

bool UAkAudioEvent::GetIsInfinite() const
{
	if (auto* EventData = Cast<UAkAudioEventData>(GetAssetData()))
	{
		return EventData->IsInfinite;
	}

	return false;
}

float UAkAudioEvent::GetMinimumDuration() const
{
	if (auto* EventData = Cast<UAkAudioEventData>(GetAssetData()))
	{
		return EventData->MinimumDuration;
	}

	return 0.f;
}

void UAkAudioEvent::SetMinimumDuration(float value)
{
	if (auto* EventData = Cast<UAkAudioEventData>(GetAssetData()))
	{
		EventData->MinimumDuration = value;
	}
}

float UAkAudioEvent::GetMaximumDuration() const
{
	if (auto* EventData = Cast<UAkAudioEventData>(GetAssetData()))
	{
		return EventData->MaximumDuration;
	}

	return 0.f;
}

void UAkAudioEvent::SetMaximumDuration(float value)
{
	if (auto* EventData = Cast<UAkAudioEventData>(GetAssetData()))
	{
		EventData->MaximumDuration = value;
	}
}

bool UAkAudioEvent::SwitchLanguage(const FString& NewAudioCulture)
{
	bool bShouldSwitchLanguage = false;
	UAkAssetPlatformData* PlatformData= nullptr;
	UAkAssetPlatformData** PlatformDataPtr = LocalizedPlatformAssetDataMap.Find(NewAudioCulture);

	if (PlatformDataPtr)
	{
		PlatformData = *PlatformDataPtr;

	}
	if (PlatformData && PlatformData->IsValidLowLevel())
	{
		bShouldSwitchLanguage = true;
	}

	if (bShouldSwitchLanguage)
	{
		if (FAkAudioDevice* AudioDevice = FAkAudioDevice::Get())
		{
			if (AudioDevice->IsEventIDActive(ShortID))
			{
				UE_LOG(LogAkAudio, Warning, TEXT("Stopping all instances of the \"%s\" event because it is being unloaded during a language change."), *GetName());
				AudioDevice->StopEventID(ShortID);
			}
		}

		UnloadLocalizedData();
		return LoadLocalizedData(NewAudioCulture);
	}

	return bShouldSwitchLanguage ;
}

void UAkAudioEvent::LoadBank()
{
	AkIntegrationBehavior::Get()->AkAudioEvent_Load(this);
}

void UAkAudioEvent::BeginDestroy()
{
	if (auto* audioDevice = FAkAudioDevice::Get())
	{
		if (audioDevice->IsEventIDActive(ShortID))
		{
			UE_LOG(LogAkAudio, Warning, TEXT("Stopping all instances of the \"%s\" event because it is being unloaded."), *GetName());
			audioDevice->StopEventID(ShortID);
		}
	}

	Super::BeginDestroy();
}

bool UAkAudioEvent::IsLocalized() const
{
	if (LocalizedPlatformAssetDataMap.Num() > 0)
	{
		return true;
	}

	return false;
}

void UAkAudioEvent::PinInGarbageCollector(uint32 PlayingID)
{
	if (TimesPinnedToGC.Increment() == 1)
	{
		AddToRoot();
	}

	if (auto* AudioDevice = FAkAudioDevice::Get())
	{
		AudioDevice->AddToPinnedEventsMap(PlayingID, this);
	}
}

void UAkAudioEvent::UnpinFromGarbageCollector(uint32 PlayingID)
{
	if (TimesPinnedToGC.Decrement() == 0)
	{
		RemoveFromRoot();
	}
}

UAkAssetData* UAkAudioEvent::CreateAssetData(UObject* parent) const
{
	return NewObject<UAkAudioEventData>(parent);
}

UAkAssetData* UAkAudioEvent::GetAssetData() const
{
#if WITH_EDITORONLY_DATA
	if (LocalizedPlatformAssetDataMap.Num() > 0 && CurrentLocalizedPlatformData)
	{
		const FString runningPlatformName(FPlatformProperties::IniPlatformName());

		if (auto platformEventData = CurrentLocalizedPlatformData->AssetDataPerPlatform.Find(runningPlatformName))
		{
			return *platformEventData;
		}
	}

	return Super::GetAssetData();
#else
	if (LocalizedPlatformAssetDataMap.Num() > 0 && CurrentLocalizedPlatformData)
	{
		return CurrentLocalizedPlatformData->CurrentAssetData;
	}

	return Super::GetAssetData();
#endif
}


bool UAkAudioEvent::LoadLocalizedBank(const FString& CurrentAudioCulture)
{
	UAkAudioEventData* EventData = Cast<UAkAudioEventData>(GetAssetData());
	if (EventData)
	{
		AssetBaseLoadBank();
		return true;
	}
	else
	{
		return false;
	}
}

bool UAkAudioEvent::LoadLocalizedData(const FString& AudioCulture, const bool& bCalledFromLoad)
{

	UAkAssetPlatformData* EventData = nullptr;
	if (UAkAssetPlatformData** EventDataPtr = LocalizedPlatformAssetDataMap.Find(AudioCulture))
	{
		EventData = *EventDataPtr;
	}
	if (EventData && EventData->IsValidLowLevel())
	{
		CurrentLocalizedPlatformData = EventData;
	}
	else
	{
		//try finding default language instead
		UAkAssetPlatformData* DefaultEventData = nullptr;
		if (auto* AudioDevice = FAkAudioDevice::Get())
		{
			FString DefaultLanguage = AudioDevice->GetDefaultLanguage();
			UE_LOG(LogAkAudio, Warning, TEXT("Event %s could not load bank data localized for %s. Will try to load default language (%s) instead."), *GetName(), *AudioCulture, *DefaultLanguage);

			if (UAkAssetPlatformData** DefaultDataPtr = LocalizedPlatformAssetDataMap.Find(DefaultLanguage))
			{
				DefaultEventData = *DefaultDataPtr;
			}
		}

		if (DefaultEventData && DefaultEventData->IsValidLowLevel())
		{
			CurrentLocalizedPlatformData = DefaultEventData;
		}

		else
		{
			UE_LOG(LogAkAudio, Warning, TEXT("Event %s could not load default language data."), *GetName());
		}
	}

	//When events grouped into banks this will just not load anything
	bool bBankLoadSuccess = LoadLocalizedBank(AudioCulture);
	bool bMediaLoadSuccess = false;
	if (bBankLoadSuccess)
	{
		//Localized media handles its own loading when serialized, but needs to be manually loaded by the parent event when switching language
		if (bCalledFromLoad)
		{
			bMediaLoadSuccess = true;
		}
		else
		{
			bMediaLoadSuccess = LoadLocalizedMedia();			
		}
	}
	return bMediaLoadSuccess && bBankLoadSuccess;
}

bool UAkAudioEvent::LoadLocalizedMedia()
{
	if (auto* CurrentEventData = Cast<UAkAudioEventData>(GetAssetData()))
	{
		for (UAkMediaAsset* MediaAsset : CurrentEventData->MediaList)
		{
			if (MediaAsset && MediaAsset->IsValidLowLevelFast())
			{
				UE_LOG(LogAkAudio, Verbose, TEXT("UAkAudioEvent::LoadLocalizedMedia: Loading media %s - %u"), *MediaAsset->MediaName, MediaAsset->Id);
				MediaAsset->LoadMedia();
			}
			else
			{
				UE_LOG(LogAkAudio, Warning, TEXT("UAkAudioEvent::LoadLocalizedMedia: Localized media reference in event %s - %u media list is invalid"), *GetName(), ShortID);
			}
		}

		CurrentEventData->LoadSwitchContainers();
		return true;
	}
	return false;
}

void UAkAudioEvent::UnloadLocalizedData()
{
	if (CurrentLocalizedPlatformData)
	{
		Super::UnloadBank();
		if (auto* CurrentEventData = Cast<UAkAudioEventData>(GetAssetData()))
		{
			for (UAkMediaAsset* MediaAsset : CurrentEventData->MediaList)
			{
				if (MediaAsset && MediaAsset->IsValidLowLevelFast())
				{
					UE_LOG(LogAkAudio, Verbose, TEXT("UAkAudioEvent::UnloadLocalizedData: Unloading media %s - %u"), *MediaAsset->MediaName, MediaAsset->Id);
					MediaAsset->UnloadMedia();
				}
				else
				{
					UE_LOG(LogAkAudio, Warning, TEXT("UAkAudioEvent::UnloadLocalizedData: Localized media reference in event %s - %u media list is invalid"), *GetName(), ShortID);
				}
			}
			CurrentEventData->UnloadSwitchContainers();
		}

		CurrentLocalizedPlatformData = nullptr;
	}
}

void UAkAudioEvent::AssetBaseLoadBank()
{
	UE_LOG(LogAkAudio, Verbose, TEXT("UAkAudioEvent::AssetBaseLoadBank: Loading bank for %s."), *GetName() );
	Super::LoadBank();
}

#if WITH_EDITOR
UAkAssetData* UAkAudioEvent::FindOrAddAssetData(const FString& Platform, const FString& Language)
{
	UAkAssetPlatformData* EventData = nullptr;
	UObject* Parent = this;

	if (!Language.IsEmpty() && Language != TEXT("SFX"))
	{
		FScopeLock autoLock(&AssetDataLock);
		auto* LanguageEntry = LocalizedPlatformAssetDataMap.Find(Language);
		if (LanguageEntry)
		{
			EventData = *LanguageEntry;

			if (EventData)
			{
				Parent = EventData;
			}
			else
			{
				LocalizedPlatformAssetDataMap.Remove(Language);
			}
		}

		if (!EventData)
		{
			check(IsInGameThread());

			auto& assetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
			auto& assetToolModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");

			FSoftObjectPath objectPath(this);

			auto basePackagePath = AkUnrealHelper::GetBaseAssetPackagePath();

			auto packagePath = objectPath.GetLongPackageName();
			packagePath.RemoveFromStart(basePackagePath);
			packagePath.RemoveFromEnd(objectPath.GetAssetName());
			packagePath = ObjectTools::SanitizeObjectPath(FPaths::Combine(AkUnrealHelper::GetLocalizedAssetPackagePath(), Language, packagePath));

			auto assetName = GetName();

			auto foundAssetData = assetRegistryModule.Get().GetAssetByObjectPath(*FPaths::Combine(packagePath, FString::Printf(TEXT("%s.%s"), *assetName, *assetName)));
			if (foundAssetData.IsValid())
			{
				EventData = Cast<UAkAssetPlatformData>(foundAssetData.GetAsset());
			}
			else
			{
				EventData = Cast<UAkAssetPlatformData>(assetToolModule.Get().CreateAsset(assetName, packagePath, UAkAssetPlatformData::StaticClass(), nullptr));
			}

			if (EventData)
			{
				Parent = EventData;

				LocalizedPlatformAssetDataMap.Add(Language, EventData);
			}
		}

		if (EventData)
		{
			return InternalFindOrAddAssetData(EventData, Platform, Parent);
		}
	}

	return UAkAssetBase::FindOrAddAssetData(Platform, Language);
}

void UAkAudioEvent::Reset(TArray<FAssetData>& InOutAssetsToDelete)
{
	if (LocalizedPlatformAssetDataMap.Num() > 0)
	{
		bChangedDuringReset = true;

		//Clean up localized platform assets
		TArray<FAssetData> AssetsToDelete;
		for (TPair<FString, UAkAssetPlatformData*> LocalizedPlatformMap : LocalizedPlatformAssetDataMap)
		{
			InOutAssetsToDelete.Add(FAssetData(LocalizedPlatformMap.Value));
		}
		LocalizedPlatformAssetDataMap.Empty();
	}

	// ALWAYS call Super::Reset() last, since it will check if things have been modified
	// before marking as dirty.
	Super::Reset(InOutAssetsToDelete);
}

bool UAkAudioEvent::NeedsRebuild(const TSet<FString>& PlatformsToBuild, const TSet<FString>& LanguagesToBuild, const ISoundBankInfoCache* SoundBankInfoCache) const
{
	bool bNeedsRebuild = Super::NeedsRebuild(PlatformsToBuild, LanguagesToBuild, SoundBankInfoCache);

	if (!PlatformAssetData)
	{
		bNeedsRebuild = false;

		TArray<TSoftObjectPtr<UAkMediaAsset>> MediaList;
		GetMediaList(MediaList);

		for (auto& Media : MediaList)
		{
			if (Media.ToSoftObjectPath().IsValid() && !Media.IsValid())
			{
				bNeedsRebuild = true;
			}
		}
	}

	if (!bNeedsRebuild)
	{
		TSet<FString> AvailableLanguages;
		for (TPair<FString, UAkAssetPlatformData*> LocalizedAssetDataEntry: LocalizedPlatformAssetDataMap)
		{
			AvailableLanguages.Add(LocalizedAssetDataEntry.Key);

			if (LanguagesToBuild.Contains(LocalizedAssetDataEntry.Key))
			{
				if (auto AssetData = LocalizedAssetDataEntry.Value)
				{
					bNeedsRebuild |= AssetData->NeedsRebuild(PlatformsToBuild, LocalizedAssetDataEntry.Key, ID, SoundBankInfoCache);
				}
				else
				{
					bNeedsRebuild = true;
				}
			}
		}

		if (!PlatformAssetData && !AvailableLanguages.Includes(LanguagesToBuild))
		{
			bNeedsRebuild = true;
		}
	}

	return bNeedsRebuild;
}

void UAkAudioEvent::PreEditUndo()
{
	UndoCompareBank = RequiredBank;
	Super::PreEditUndo();
}

void UAkAudioEvent::PostEditUndo()
{
	if (UndoCompareBank != RequiredBank) {
		UndoFlag = true;
	}
	Super::PostEditUndo();
	UndoFlag = false;
}

#if UE_4_25_OR_LATER
void UAkAudioEvent::PreEditChange(FProperty* PropertyAboutToChange)
#else
void UAkAudioEvent::PreEditChange(UProperty* PropertyAboutToChange)
#endif
{
	if (PropertyAboutToChange->GetFName() == GET_MEMBER_NAME_CHECKED(UAkAudioEvent, RequiredBank))
	{
		LastRequiredBank = RequiredBank;
	}
	Super::PreEditChange(PropertyAboutToChange);
}

void UAkAudioEvent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property)
	{
		if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UAkAudioEvent, RequiredBank))
		{
			UpdateRequiredBanks();
		}
	}
	else if (UndoFlag)
	{
		LastRequiredBank = UndoCompareBank;
		UpdateRequiredBanks();
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);

}

void UAkAudioEvent::ClearRequiredBank()
{
	if (RequiredBank->IsValidLowLevel())
	{
		RequiredBank->RemoveAkAudioEvent(this);
	}
	LastRequiredBank = RequiredBank;
	RequiredBank = nullptr;
}

void UAkAudioEvent::UpdateRequiredBanks()
{
	if (LastRequiredBank->IsValidLowLevel())
	{
		LastRequiredBank->RemoveAkAudioEvent(this);
	}

	if (RequiredBank->IsValidLowLevel())
	{
		RequiredBank->AddAkAudioEvent(this);
	}
}
#endif

bool UAkAudioEvent::IsReadyForAsyncPostLoad() const
{
	if (auto AssetData = GetAssetData())
	{
		return AssetData->IsReadyForAsyncPostLoad();
	}

	return true;
}

bool UAkAudioEvent::IsLocalizationReady() const
{
	//check if all referenced media has finished loading
	if (UAkAudioEventData* EventData = Cast<UAkAudioEventData>(GetAssetData()))
	{
		return EventData->IsMediaReady();
	}
	return true;
}