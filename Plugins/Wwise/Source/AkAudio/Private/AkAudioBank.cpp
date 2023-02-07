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

#include "AkAudioBank.h"

#include "AkAudioDevice.h"
#include "AkAudioEvent.h"
#include "AkCustomVersion.h"
#include "AkMediaAsset.h"
#include "AkUnrealHelper.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "IntegrationBehavior/AkIntegrationBehavior.h"

#if WITH_EDITOR
#include "AssetTools/Public/AssetToolsModule.h"
#include "UnrealEd/Public/ObjectTools.h"
#endif

void UAkAudioBank::LoadBank()
{
	AkIntegrationBehavior::Get()->AkAudioBank_Load(this);

#if WITH_EDITOR
	if (!ID.IsValid())
	{
		ID = FGuid::NewGuid();
	}
#endif
}

void UAkAudioBank::UnloadBank()
{
	AkIntegrationBehavior::Get()->AkAudioBank_Unload(this);
}

bool UAkAudioBank::SwitchLanguage(const FString& NewAudioCulture)
{
	UnloadLocalizedData();
	return LoadLocalizedData(NewAudioCulture);

}

#if WITH_EDITOR || WITH_EDITORONLY_DATA
void UAkAudioBank::AddAkAudioEvent(UAkAudioEvent* Event)
{
	LinkedAkEvents.Add(TSoftObjectPtr<UAkAudioEvent>(Event));
}

void UAkAudioBank::RemoveAkAudioEvent(UAkAudioEvent* Event)
{
	LinkedAkEvents.Remove(TSoftObjectPtr<UAkAudioEvent>(Event));
}

void UAkAudioBank::PopulateAkAudioEvents()
{
	LinkedAkEvents.Empty();
	auto& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	if (AssetRegistryModule.Get().IsLoadingAssets())
	{
		AssetRegistryModule.Get().OnFilesLoaded().AddLambda(
			[this] 
			{
				FindObjectsReferencingThis<UAkAudioEvent>(UAkAudioEvent::StaticClass(), LinkedAkEvents);
			});
	}
	else
	{
		FindObjectsReferencingThis<UAkAudioEvent>(UAkAudioEvent::StaticClass(), LinkedAkEvents);
	}
}
#endif

bool UAkAudioBank::LegacyLoad()
{
	if (!IsRunningCommandlet())
	{
		FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			AkBankID BankID;
			AKRESULT eResult = AudioDevice->LoadBank(this, BankID);
			if (eResult == AK_Success)
			{
				return true;
			}
		}
	}

	return false;
}

bool UAkAudioBank::LegacyLoad(FWaitEndBankAction* LoadBankLatentAction)
{
	if (!IsRunningCommandlet())
	{
		FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			AKRESULT eResult = AudioDevice->LoadBank(this, LoadBankLatentAction);
			if (eResult == AK_Success)
			{
				return true;
			}
		}
	}

	return false;
}

bool UAkAudioBank::LegacyLoadAsync(void* in_pfnBankCallback, void* in_pCookie)
{
	if (!IsRunningCommandlet())
	{
		FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			AkBankID BankID;
			AKRESULT eResult = AudioDevice->LoadBank(this, (AkBankCallbackFunc)in_pfnBankCallback, in_pCookie, BankID);
			if (eResult == AK_Success)
			{
				return true;
			}
		}
	}

	return false;
}

bool UAkAudioBank::LegacyLoadAsync(const FOnAkBankCallback& BankLoadedCallback)
{
	if (!IsRunningCommandlet())
	{
		FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			AkBankID BankID;
			AKRESULT eResult = AudioDevice->LoadBankAsync(this, BankLoadedCallback, BankID);
			if (eResult == AK_Success)
			{
				return true;
			}
		}
	}

	return false;
}

void UAkAudioBank::LegacyUnload()
{
	if (!IsRunningCommandlet())
	{
		FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			AudioDevice->UnloadBank(this);
		}
	}
}

void UAkAudioBank::LegacyUnload(FWaitEndBankAction* UnloadBankLatentAction)
{
	if (!IsRunningCommandlet())
	{
		FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			AudioDevice->UnloadBank(this, UnloadBankLatentAction);
		}
	}
}

void UAkAudioBank::LegacyUnloadAsync(void* in_pfnBankCallback, void* in_pCookie)
{
	if (!IsRunningCommandlet())
	{
		AKRESULT eResult = AK_Fail;
		FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			eResult = AudioDevice->UnloadBank(this, (AkBankCallbackFunc)in_pfnBankCallback, in_pCookie);
			if (eResult != AK_Success)
			{
				UE_LOG(LogAkAudio, Warning, TEXT("Failed to unload SoundBank %s"), *GetName());
			}
		}
	}
}

void UAkAudioBank::LegacyUnloadAsync(const FOnAkBankCallback& BankUnloadedCallback)
{
	if (!IsRunningCommandlet())
	{
		AKRESULT eResult = AK_Fail;
		FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			eResult = AudioDevice->UnloadBankAsync(this, BankUnloadedCallback);
			if (eResult != AK_Success)
			{
				UE_LOG(LogAkAudio, Warning, TEXT("Failed to unload SoundBank %s"), *GetName());
			}
		}
	}
}

UAkAssetData* UAkAudioBank::CreateAssetData(UObject* parent) const
{
	return NewObject<UAkAssetData>(parent);
}

UAkAssetData* UAkAudioBank::GetAssetData() const
{
#if WITH_EDITORONLY_DATA
	if (IsLocalized() && CurrentLocalizedPlatformAssetData)
	{
		const FString RunningPlatformName(FPlatformProperties::IniPlatformName());
		if (UAkAssetData** AssetDataPtr = CurrentLocalizedPlatformAssetData->AssetDataPerPlatform.Find(RunningPlatformName))
		{
			if (UAkAssetData* AssetData = *AssetDataPtr)
			{
				return AssetData;
			}
		}
		
		UE_LOG(LogAkAudio, Warning, TEXT("UAkAudioBank::GetAssetData: Could not find data for platform %s for SoundBank %s"),*RunningPlatformName, *GetName());
		return nullptr;
	}

	return Super::GetAssetData();
#else
	if (IsLocalized() && CurrentLocalizedPlatformAssetData)
	{
		return CurrentLocalizedPlatformAssetData->CurrentAssetData;
	}

	return Super::GetAssetData();
#endif
}

bool UAkAudioBank::LoadLocalizedData(const FString& AudioCulture)
{
	if (UAkAssetPlatformData** BankAssetDataPtr = LocalizedPlatformAssetDataMap.Find(AudioCulture))
	{
		if (UAkAssetPlatformData* BankAssetData = *BankAssetDataPtr)
		{
			CurrentLocalizedPlatformAssetData = BankAssetData;
			AssetBaseLoadBank();
			return true;
		}
	}

	UE_LOG(LogAkAudio, Warning, TEXT("UAkAudioBank::LoadLocalizedData: Could not find localized data for language %s for SoundBank %s"),*AudioCulture, *GetName());
	return false;
}

void UAkAudioBank::UnloadLocalizedData()
{
	AssetBaseUnloadBank();
}

void UAkAudioBank::AssetBaseLoadBank()
{
	UE_LOG(LogAkAudio, Verbose, TEXT("UAkAudioBank::AssetBaseLoadBank: Loading bank for %s."), *GetName());
	Super::LoadBank();
}

void UAkAudioBank::AssetBaseUnloadBank()
{
	Super::UnloadBank();
	CurrentLocalizedPlatformAssetData = nullptr;
}

void UAkAudioBank::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (Ar.IsCooking())
	{
		Ar << LinkedAkEvents;
	}
	else if (Ar.IsLoading())
	{
#if WITH_EDITOR|| WITH_EDITORONLY_DATA
		PopulateAkAudioEvents();
#else
		Ar << LinkedAkEvents;
#endif
	}
}

void UAkAudioBank::PostLoad()
{
	Super::PostLoad();
	LoadedBankName = GetName();
}

#if WITH_EDITOR
UAkAssetData* UAkAudioBank::FindOrAddAssetData(const FString& Platform, const FString& Language)
{
	UAkAssetPlatformData* BankData = nullptr;
	UObject* Parent = this;

	if (!Language.IsEmpty() && Language != TEXT("SFX") )
	{
		FScopeLock autoLock(&AssetDataLock);

		if (UAkAssetPlatformData** BankDataPtr = LocalizedPlatformAssetDataMap.Find(Language))
		{
			BankData = *BankDataPtr;
			if (BankData)
			{
				Parent = BankData;
			}
			else
			{
				LocalizedPlatformAssetDataMap.Remove(Language);
			}
		}

		if (!BankData)
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
				BankData = Cast<UAkAssetPlatformData>(foundAssetData.GetAsset());
			}
			else
			{
				BankData = Cast<UAkAssetPlatformData>(assetToolModule.Get().CreateAsset(assetName, packagePath, UAkAssetPlatformData::StaticClass(), nullptr));
			}

			if (BankData)
			{
				Parent = BankData;
				LocalizedPlatformAssetDataMap.Add(Language, BankData);
			}
		}

		//Make sure platform asset data asset can no longer contain aux bus media (which is already in the Init bank)
		if (BankData && BankData->AssetDataPerPlatform.Contains(Platform))
		{
			if (auto* PlatformData = Cast<UAkAssetDataWithMedia>(BankData->AssetDataPerPlatform[Platform]))
			{
				BankData->AssetDataPerPlatform.Remove(Platform);
			}
		}

		if (BankData)
		{
			return InternalFindOrAddAssetData(BankData, Platform, Parent);
		}
	}
	else
	{
		FScopeLock autoLock(&AssetDataLock);

		//Make sure this asset no can no longer reference aux bus media (which is already referenced by the Init bank)
		if (PlatformAssetData && PlatformAssetData->AssetDataPerPlatform.Contains(Platform))
		{
			if (auto* PlatformData = Cast<UAkAssetDataWithMedia>(PlatformAssetData->AssetDataPerPlatform[Platform]))
			{
				PlatformAssetData->AssetDataPerPlatform.Remove(Platform);
			}
		}
	}

	return UAkAssetBase::FindOrAddAssetData(Platform, Language);
}

void UAkAudioBank::Reset(TArray<FAssetData>& InOutAssetsToDelete)
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
	LocalizedPlatformAssetDataMap.Empty();

	// ALWAYS call Super::Reset() last, since it will check if things have been modified
	// before marking as dirty.
	Super::Reset(InOutAssetsToDelete);
}

bool UAkAudioBank::NeedsRebuild(const TSet<FString>& PlatformsToBuild, const TSet<FString>& LanguagesToBuild, const ISoundBankInfoCache* SoundBankInfoCache) const
{
	bool result = Super::NeedsRebuild(PlatformsToBuild, LanguagesToBuild, SoundBankInfoCache);

	if (!PlatformAssetData)
	{
		result = false;

		TArray<TSoftObjectPtr<UAkMediaAsset>> mediaList;
		GetMediaList(mediaList);

		for (auto& media : mediaList)
		{
			if (media.ToSoftObjectPath().IsValid() && !media.IsValid())
			{
				result = true;
			}
		}
	}

	if (!result)
	{
		TSet<FString> AvailableLanguages;
		for (auto& LocalizedAssetEntry : LocalizedPlatformAssetDataMap)
		{
			AvailableLanguages.Add(LocalizedAssetEntry.Key);

			if (LanguagesToBuild.Contains(LocalizedAssetEntry.Key))
			{
				if (auto AssetData = LocalizedAssetEntry.Value)
				{
					result |= AssetData->NeedsRebuild(PlatformsToBuild, LocalizedAssetEntry.Key, ID, SoundBankInfoCache);
				}
				else
				{
					result = true;
				}
			}
		}

		if (!PlatformAssetData && !AvailableLanguages.Includes(LanguagesToBuild))
		{
			result = true;
		}
	}

	return result;
}
#endif
