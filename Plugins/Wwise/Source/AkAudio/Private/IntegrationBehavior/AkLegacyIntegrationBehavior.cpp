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

#include "AkLegacyIntegrationBehavior.h"

#include "AkAssetBase.h"
#include "AkAudioBank.h"
#include "AkGameplayStatics.h"
#include "CoreUObject/Public/UObject/UObjectIterator.h"
#include "LegacyIOHook/AkFilePackageLowLevelIO.h"
#include "LegacyIOHook/AkUnrealLegacyIOHook.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"

namespace AkLegacyIntegrationBehavior_Helpers
{
	using FAkLegacyFilePackageIO = CAkFilePackageLowLevelIO<FAkUnrealLegacyIOHook, CAkDiskPackage, AkLegacyFileCustomParamPolicy>;
}

// AkAssetData
AKRESULT AkLegacyIntegrationBehavior::AkAssetData_LoadBank(UAkAssetData* AkAssetData)
{
	return AK_Success;
}

// AkAudioBank
void AkLegacyIntegrationBehavior::AkAudioBank_Load(UAkAudioBank* AkAudioBank)
{
	if (AkAudioBank->AutoLoad && !AkAudioBank->HasAnyFlags(RF_ClassDefaultObject))
	{
		AkAudioBank->LegacyLoad();
	}
}

void AkLegacyIntegrationBehavior::AkAudioBank_Unload(UAkAudioBank* AkAudioBank)
{
	if (AkAudioBank->AutoLoad && !AkAudioBank->HasAnyFlags(RF_ClassDefaultObject))
	{
		AkAudioBank->LegacyUnload();
	}
}

// AkAudioDevice
AKRESULT AkLegacyIntegrationBehavior::AkAudioDevice_ClearBanks(FAkAudioDevice* AkAudioDevice)
{
	AKRESULT eResult = AK::SoundEngine::ClearBanks();
	if (eResult == AK_Success && AkAudioDevice->AkBankManager)
	{
		AkAudioDevice->AkBankManager->ClearLoadedBanks();
	}

	return eResult;
}

AKRESULT AkLegacyIntegrationBehavior::AkAudioDevice_LoadInitBank(FAkAudioDevice* AkAudioDevice)
{
	AkBankID BankID;
	return AK::SoundEngine::LoadBank(TCHAR_TO_AK(AkInitBankName), BankID);
}

bool AkLegacyIntegrationBehavior::AkAudioDevice_LoadAllFilePackages(FAkAudioDevice* AkAudioDevice)
{
	TArray<FString> FoundPackages;
	FString BaseBankPath = AkAudioDevice->GetBasePath();
	bool eResult = true;
	IFileManager::Get().FindFilesRecursive(FoundPackages, *BaseBankPath, TEXT("*.pck"), true, false);
	for (auto& Package : FoundPackages)
	{
		AkUInt32 PackageID;
		FString PackageName = FPaths::GetCleanFilename(Package);

		AKRESULT eTempResult = AkAudioDevice->IOHook->LoadFilePackage(TCHAR_TO_AK(*PackageName), PackageID);
		if (eTempResult != AK_Success)
		{
			UE_LOG(LogAkAudio, Error, TEXT("Failed to load file package %s"), *PackageName);
			eResult = false;
		}
	}

	return eResult;
}

bool AkLegacyIntegrationBehavior::AkAudioDevice_UnloadAllFilePackages(FAkAudioDevice* AkAudioDevice)
{
	return AkAudioDevice->IOHook->UnloadAllFilePackages() == AK_Success;
}

void AkLegacyIntegrationBehavior::AkAudioDevice_LoadAllReferencedBanks(FAkAudioDevice* AkAudioDevice)
{
	AkAudioDevice->LoadAllFilePackages();
	AkAudioDevice->LoadInitBank();

	// Load any banks that are in memory that haven't been loaded yet
	for (TObjectIterator<UAkAudioBank> It; It; ++It)
	{
		if ((*It)->AutoLoad)
		{
			(*It)->LegacyLoad();
		}
	}

	AkAudioDevice->OnSoundbanksLoaded.Broadcast();
}

void AkLegacyIntegrationBehavior::AkAudioDevice_SetCurrentAudioCulture(const FString& NewWwiseLanguage)
{
	AK::StreamMgr::SetCurrentLanguage(TCHAR_TO_AK(*NewWwiseLanguage));
}

void AkLegacyIntegrationBehavior::AkAudioDevice_SetCurrentAudioCultureAsync(FAkAudioDevice* AkAudioDevice, const FString& NewWwiseLanguage, const FOnSetCurrentAudioCultureCompleted& CompletedCallback)
{
	AkAudioDevice_SetCurrentAudioCulture(NewWwiseLanguage);
	CompletedCallback.ExecuteIfBound(true);
}

void AkLegacyIntegrationBehavior::AkAudioDevice_SetCurrentAudioCultureAsync(FAkAudioDevice* AkAudioDevice, const FString& NewWwiseLanguage, FSetCurrentAudioCultureAction* LatentAction)
{
	AkAudioDevice_SetCurrentAudioCulture(NewWwiseLanguage);
	LatentAction->ActionDone = true;
}

void AkLegacyIntegrationBehavior::AkAudioDevice_CreateIOHook(FAkAudioDevice* AkAudioDevice)
{
	AkAudioDevice->IOHook = new AkLegacyIntegrationBehavior_Helpers::FAkLegacyFilePackageIO();
}

void AkLegacyIntegrationBehavior::AkAudioDevice_LoadInitialData(FAkAudioDevice* AkAudioDevice)
{
	AkAudioDevice->LoadAllReferencedBanks();
}

#if WITH_EDITOR
void AkLegacyIntegrationBehavior::AkAudioDevice_ReloadAllSoundData(FAkAudioDevice* AkAudioDevice)
{
	AkAudioDevice->ReloadAllReferencedBanks();
}
#endif

// AkAudioEvent
void AkLegacyIntegrationBehavior::AkAudioEvent_Load(UAkAudioEvent* AkAudioEvent)
{
	// Do nothing
}

// AkGameplayStatics
void AkLegacyIntegrationBehavior::AkGameplayStatics_LoadBank(UAkAudioBank* AkAudioBank, const FString& BankName, FWaitEndBankAction* NewAction)
{
	if (AkAudioBank)
	{
		if (!AkAudioBank->LegacyLoad(NewAction))
		{
			NewAction->ActionDone = true;
		}
	}
	else
	{
		UAkGameplayStatics::LoadBankByName(BankName);

		NewAction->ActionDone = true;
	}
}

void AkLegacyIntegrationBehavior::AkGameplayStatics_LoadBankAsync(UAkAudioBank* AkAudioBank, const FOnAkBankCallback& BankLoadedCallback)
{
	if (AkAudioBank)
	{
		AkAudioBank->LegacyLoadAsync(BankLoadedCallback);
	}
	else
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::LoadBankAsync: NULL AudioBank specified!"));
	}
}

void AkLegacyIntegrationBehavior::AkGameplayStatics_LoadBankByName(const FString& BankName)
{
	if (BankName.IsEmpty())
	{
		UE_LOG(LogScript, Error, TEXT("UAkGameplayStatics::LoadBank: Empty bank name specified."));
		return;
	}

	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		if (AudioDevice->GetAkBankManager() != NULL)
		{
			for (TObjectIterator<UAkAudioBank> Iter; Iter; ++Iter)
			{
				if (Iter->GetName() == BankName)
				{
					Iter->LegacyLoad();
					return;
				}
			}

			// Bank not found in the assets, load it by name anyway
		}

		AkUInt32 bankID;
		AudioDevice->LoadBank(BankName, bankID);
	}
}

void AkLegacyIntegrationBehavior::AkGameplayStatics_LoadBanks(const TArray<UAkAudioBank*>& SoundBanks, bool SynchronizeSoundBanks)
{
	if (SynchronizeSoundBanks)
	{
		TSet<UAkAudioBank*> BanksToUnload;
		TSet<UAkAudioBank*> BanksToLoad;
		TSet<UAkAudioBank*> InputBankSet(SoundBanks);
		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice)
		{
			FAkBankManager* BankManager = AkAudioDevice->GetAkBankManager();
			if (BankManager)
			{
				const TSet<UAkAudioBank*> LoadedBanks = BankManager->GetLoadedBankList();

				// We load what's in the input set, but not in the already loaded set
				BanksToLoad = InputBankSet.Difference(LoadedBanks);

				// We unload what's in the loaded set but not in the input set
				BanksToUnload = LoadedBanks.Difference(InputBankSet);
			}
			else
			{
				UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::LoadBanks: Bank Manager unused, and CleanUpBanks set to true!"));
			}
		}
		for (TSet<UAkAudioBank*>::TConstIterator LoadIter(BanksToLoad); LoadIter; ++LoadIter)
		{
			if (*LoadIter)
			{
				(*LoadIter)->LegacyLoad();
			}
		}

		for (TSet<UAkAudioBank*>::TConstIterator UnloadIter(BanksToUnload); UnloadIter; ++UnloadIter)
		{
			if (*UnloadIter)
			{
				(*UnloadIter)->LegacyUnload();
			}
		}
	}
	else
	{
		for (TArray<UAkAudioBank*>::TConstIterator LoadIter(SoundBanks); LoadIter; ++LoadIter)
		{
			if (*LoadIter)
			{
				(*LoadIter)->LegacyLoad();
			}
		}
	}
}

void AkLegacyIntegrationBehavior::AkGameplayStatics_UnloadBank(UAkAudioBank* Bank, const FString& BankName, FWaitEndBankAction* NewAction)
{
	if (Bank)
	{
		Bank->LegacyUnload(NewAction);
	}
	else
	{
		UAkGameplayStatics::UnloadBankByName(BankName);
		NewAction->ActionDone = true;
	}
}

void AkLegacyIntegrationBehavior::AkGameplayStatics_UnloadBankAsync(UAkAudioBank* Bank, const FOnAkBankCallback& BankUnloadedCallback)
{
	if (Bank)
	{
		Bank->LegacyUnloadAsync(BankUnloadedCallback);
	}
	else
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::UnloadBankAsync: NULL AudioBank specified!"));
	}
}

void AkLegacyIntegrationBehavior::AkGameplayStatics_UnloadBankByName(const FString& BankName)
{
	if (FAkAudioDevice* AudioDevice = FAkAudioDevice::Get())
	{
		if (AudioDevice->GetAkBankManager() != NULL)
		{
			for (TObjectIterator<UAkAudioBank> Iter; Iter; ++Iter)
			{
				if (Iter->GetName() == BankName)
				{
					Iter->LegacyUnload();
					return;
				}
			}

			// Bank not found in the assets, unload it by name anyway
		}

		AudioDevice->UnloadBank(BankName);
	}
}

void AkLegacyIntegrationBehavior::FAkSDKExternalSourceArray_Ctor(FAkSDKExternalSourceArray* Instance, const TArray<FAkExternalSourceInfo>& BlueprintArray)
{
	if (auto* AudioDevice = FAkAudioDevice::Get())
	{
		for (auto& externalSourceInfo : BlueprintArray)
		{
			AkOSChar* OsCharArray = nullptr;

			auto externalFileName = externalSourceInfo.FileName;
			if (FPaths::GetExtension(externalFileName).IsEmpty())
			{
				externalFileName += TEXT(".wem");
			}
			OsCharArray = (AkOSChar*)FMemory::Malloc((externalFileName.Len() + 1) * sizeof(AkOSChar));
			FPlatformString::Strcpy(OsCharArray, externalFileName.Len(), TCHAR_TO_AK(*(externalFileName)));

			Instance->ExternalSourceArray.Emplace(OsCharArray, FAkAudioDevice::GetIDFromString(externalSourceInfo.ExternalSrcName), (AkCodecID)externalSourceInfo.CodecID);
		}
	}
}
