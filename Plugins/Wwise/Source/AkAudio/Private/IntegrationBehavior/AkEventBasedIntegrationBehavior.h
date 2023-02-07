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

#pragma once

#include "AkIntegrationBehavior.h"

class AkEventBasedIntegrationBehavior : public AkIntegrationBehavior
{
public:
	// AkAssetBase
	AKRESULT AkAssetData_LoadBank(UAkAssetData* AkAssetData) override;

	// AkAudioBank
	void AkAudioBank_Load(UAkAudioBank* AkAudioBank) override;
	void AkAudioBank_Unload(UAkAudioBank* AkAudioBank) override;

	// AkAudioDevice
	AKRESULT AkAudioDevice_ClearBanks(FAkAudioDevice* AkAudioDevice) override;
	AKRESULT AkAudioDevice_LoadInitBank(FAkAudioDevice* AkAudioDevice) override;
	bool AkAudioDevice_LoadAllFilePackages(FAkAudioDevice* AkAudioDevice) override;
	bool AkAudioDevice_UnloadAllFilePackages(FAkAudioDevice* AkAudioDevice) override;
	void AkAudioDevice_LoadAllReferencedBanks(FAkAudioDevice* AkAudioDevice) override;
	void AkAudioDevice_SetCurrentAudioCulture(const FString& NewWwiseLanguage) override;
	void AkAudioDevice_SetCurrentAudioCultureAsync(FAkAudioDevice* AkAudioDevice, const FString& NewWwiseLanguage, FSetCurrentAudioCultureAction* LatentAction) override;
	void AkAudioDevice_SetCurrentAudioCultureAsync(FAkAudioDevice* AkAudioDevice, const FString& NewWwiseLanguage, const FOnSetCurrentAudioCultureCompleted& CompletedCallback) override;
	void AkAudioDevice_CreateIOHook(FAkAudioDevice* AkAudioDevice) override;
	void AkAudioDevice_LoadInitialData(FAkAudioDevice* AkAudioDevice) override;
#if WITH_EDITOR
	void AkAudioDevice_UnloadAllSoundData(FAkAudioDevice* AkAudioDevice) override;
	void AkAudioDevice_ReloadAllSoundData(FAkAudioDevice* AkAudioDevice) override;
	void LoadAllSoundData(FAkAudioDevice* AkAudioDevice);
#endif

	// AkAudioEvent
	void AkAudioEvent_Load(UAkAudioEvent* AkAudioEvent) override;

	// AkGameplayStatics
	void AkGameplayStatics_LoadBank(UAkAudioBank* AkAudioBank, const FString& BankName, FWaitEndBankAction* NewAction) override;
	void AkGameplayStatics_LoadBankAsync(UAkAudioBank* AkAudioBank, const FOnAkBankCallback& BankLoadedCallback) override;
	void AkGameplayStatics_LoadBankByName(const FString& BankName) override;
	void AkGameplayStatics_LoadBanks(const TArray<UAkAudioBank*>& SoundBanks, bool SynchronizeSoundBanks) override;
	void AkGameplayStatics_UnloadBank(UAkAudioBank* Bank, const FString& BankName, FWaitEndBankAction* NewAction) override;
	void AkGameplayStatics_UnloadBankAsync(UAkAudioBank* Bank, const FOnAkBankCallback& BankUnloadedCallback) override;
	void AkGameplayStatics_UnloadBankByName(const FString& BankName) override;

	// FAkSDKExternalSourceArray
	void FAkSDKExternalSourceArray_Ctor(FAkSDKExternalSourceArray* Instance, const TArray<FAkExternalSourceInfo>& BlueprintArray) override;

	FDelegateHandle OnMediaFreedHandle;

};