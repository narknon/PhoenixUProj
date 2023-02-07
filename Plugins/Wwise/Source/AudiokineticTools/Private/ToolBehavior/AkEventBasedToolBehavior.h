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

#include "AkToolBehavior.h"

class AkEventBasedToolBehavior : public AkToolBehavior
{
public:
	using Super = AkToolBehavior;

	// CreateSoundDataWidget
	bool CreateSoundDataWidget(const TSharedRef<SWindow>& Window, TArray<TWeakObjectPtr<UAkAudioBank>>* SoundBanks, bool ProjectSave) override;

	// AkAssetManagementManager
	bool AkAssetManagementManager_ModifyProjectSettings(FString& ProjectContent) override;

	// AkAssetDatabase
	FString AkAssetDatabase_GetInitBankPackagePath() const override;
	bool AkAssetDatabase_ValidateAssetId(FGuid& outId) override;
	bool AkAssetDatabase_Remove(AkAssetDatabase* Instance, const FAssetData& AssetData) override;

	// AkSoundDataBuilder
	bool AkSoundDataBuilder_GetBankName(AkSoundDataBuilder* Instance, UAkAudioBank* Bank, const TSet<FString>& BanksToGenerate, FString& bankName) override;

	// CookAkSoundDataTask
	TSharedPtr<AkSoundDataBuilder, ESPMode::ThreadSafe> CookAkSoundDataTask_CreateBuilder(const AkSoundDataBuilder::InitParameters& InitParameters) override;

	// WwiseConsoleAkSoundDataBuilder
	FString WwiseConsoleAkSoundDataBuilder_AudioBankEventIncludes() const override;
	FString WwiseConsoleAkSoundDataBuilder_AudioBankAuxBusIncludes() const override;

	// AkAssetFactory
	bool AkAssetFactory_ValidNewAssetPath(FName Name, const FString& AssetPath, const UClass* AssetClass) const override;
};
