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

#include "AkLegacyToolBehavior.h"

#include "AkAcousticTexture.h"
#include "AkAudioBank.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkGroupValue.h"
#include "AkInitBank.h"
#include "AkRtpc.h"
#include "AkTrigger.h"
#include "AkFolder.h"
#include "AkUnrealHelper.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "AssetManagement/WwiseConsoleAkSoundDataBuilder.h"
#include "Misc/MessageDialog.h"
#include "SlateCore/Public/Widgets/SWindow.h"
#include "UI/SLegacyGenerateSoundBanks.h"

bool AkLegacyToolBehavior::CreateSoundDataWidget(const TSharedRef<SWindow>& Window, TArray<TWeakObjectPtr<UAkAudioBank>>* SoundBanks, bool ProjectSave)
{
	TSharedRef<SLegacyGenerateSoundBanks> WindowContent = SNew(SLegacyGenerateSoundBanks, SoundBanks);
	WindowContent->SetShouldSaveWwiseProject(ProjectSave);
	if (!WindowContent->ShouldDisplayWindow())
	{
		return false;
	}

	// Add our SGenerateSoundBanks to the window
	Window->SetContent(WindowContent);

	// Set focus to our SGenerateSoundBanks widget, so our keyboard keys work right off the bat
	Window->SetWidgetToFocusOnActivate(WindowContent);

	return true;
}

bool AkLegacyToolBehavior::AkAssetManagementManager_ModifyProjectSettings(FString& ProjectContent)
{
	bool modified = Super::AkAssetManagementManager_ModifyProjectSettings(ProjectContent);

	static const TCHAR* PropertiesToRemove[] = {
		TEXT("<Property Name=\"GenerateMainSoundBank\" Type=\"bool\" Value=\"False\"/>"),
		TEXT("<Property Name=\"GenerateSoundBankXML\" Type=\"bool\" Value=\"False\"/>"),
	};

	for (auto toRemove : PropertiesToRemove)
	{
		if (ProjectContent.Contains(toRemove))
		{
			ProjectContent.ReplaceInline(toRemove, TEXT(""));
			modified = true;
		}
	}

	return modified;
}

FString AkLegacyToolBehavior::AkAssetDatabase_GetInitBankPackagePath() const
{
	return TEXT("/Game");
}

bool AkLegacyToolBehavior::AkAssetDatabase_ValidateAssetId(FGuid& outId)
{
	if (!outId.IsValid())
	{
		outId = FGuid::NewGuid();
	}

	return true;
}

bool AkLegacyToolBehavior::AkAssetDatabase_Remove(AkAssetDatabase* Instance, const FAssetData& AssetData)
{
	auto name = AssetData.AssetName.ToString();

	auto assetKlass = AssetData.GetClass();

	if (assetKlass->IsChildOf<UAkAcousticTexture>())
	{
		Instance->AcousticTextureMap.RemoveByName(name);
	}
	else if (assetKlass->IsChildOf<UAkAudioEvent>())
	{
		Instance->EventMap.RemoveByName(name);
	}
	else if (assetKlass->IsChildOf<UAkAuxBus>())
	{
		Instance->AuxBusMap.RemoveByName(name);
	}
	else if (assetKlass->IsChildOf<UAkGroupValue>())
	{
		Instance->GroupValueMap.RemoveByName(name);
	}
	else if (assetKlass->IsChildOf<UAkTrigger>())
	{
		Instance->TriggerMap.RemoveByName(name);
	}
	else if (assetKlass->IsChildOf<UAkRtpc>())
	{
		Instance->RtpcMap.RemoveByName(name);
	}
	else if (assetKlass->IsChildOf<UAkAudioBank>())
	{
		Instance->BankMap.RemoveByName(name);
	}
	else if (assetKlass->IsChildOf<UAkFolder>())
	{
		Instance->FolderMap.RemoveByName(name);
	}
	else if (assetKlass->IsChildOf<UAkInitBank>())
	{
		Instance->InitBank = nullptr;
	}
	else
	{
		return false;
	}

	return Instance->AudioTypeMap.RemoveByName(name) > 0;
}

// AkSoundDataBuilder
bool AkLegacyToolBehavior::AkSoundDataBuilder_GetBankName(AkSoundDataBuilder* Instance, UAkAudioBank* Bank, const TSet<FString>& BanksToGenerate, FString& bankName)
{
	bankName = Bank->GetName();
	return BanksToGenerate.Contains(bankName);
}

// CookAkSoundDataTask
TSharedPtr<AkSoundDataBuilder, ESPMode::ThreadSafe> AkLegacyToolBehavior::CookAkSoundDataTask_CreateBuilder(const AkSoundDataBuilder::InitParameters& InitParameters)
{
	return MakeShared<WwiseConsoleAkSoundDataBuilder, ESPMode::ThreadSafe>(InitParameters);
}

// WwiseConsoleAkSoundDataBuilder
FString AkLegacyToolBehavior::WwiseConsoleAkSoundDataBuilder_AudioBankEventIncludes() const
{
	return TEXT("\"\tEvent\tStructure\tMedia");
}

FString AkLegacyToolBehavior::WwiseConsoleAkSoundDataBuilder_AudioBankAuxBusIncludes() const
{
	return TEXT("\"\tStructure\tMedia");
}

// AkAssetFactory
bool AkLegacyToolBehavior::AkAssetFactory_ValidNewAssetPath(FName Name, const FString& AssetPath, const UClass* AssetClass) const
{
	auto assetPackagePath = AkUnrealHelper::GetBaseAssetPackagePath();

	if (AssetPath.StartsWith(AkUnrealHelper::GetBaseAssetPackagePath(), ESearchCase::IgnoreCase))
	{
		const FFormatNamedArguments Args
		{
			{ TEXT("ObjectName"), FText::FromName(Name) },
			{ TEXT("PathName"), FText::FromString(AssetPath) },
			{ TEXT("WwisePath"), FText::FromString(assetPackagePath) }
		};

		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetFactory", "CannotCreateAssetInPathLegacy", "Cannot create new asset '{ObjectName}' in path '{PathName}'. You can't put assets under '{WwisePath}' folder."), Args));
		return false;
	}

	return true;
}
