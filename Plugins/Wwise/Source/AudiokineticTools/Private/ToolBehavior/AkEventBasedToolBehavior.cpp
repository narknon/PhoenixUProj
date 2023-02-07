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

#include "AkEventBasedToolBehavior.h"

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
#include "AkWaapiClient.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "AssetManagement/WaapiAkSoundDataBuilder.h"
#include "AssetManagement/WwiseConsoleAkSoundDataBuilder.h"
#include "Misc/MessageDialog.h"
#include "SlateCore/Public/Widgets/SWindow.h"
#include "UI/SGenerateSoundBanks.h"

bool AkEventBasedToolBehavior::CreateSoundDataWidget(const TSharedRef<SWindow>& Window, TArray<TWeakObjectPtr<UAkAudioBank>>* SoundBanks, bool ProjectSave)
{
	TSharedRef<SGenerateSoundBanks> WindowContent = SNew(SGenerateSoundBanks);
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

bool AkEventBasedToolBehavior::AkAssetManagementManager_ModifyProjectSettings(FString& ProjectContent)
{
	static const auto PropertyListStart = TEXT("<PropertyList>");

	static const auto EnvironmentalSettingsEnd = TEXT("</EnvironmentalSettings>");

	static const auto LogCentralIgnoreListBegin = TEXT("<LogCentralIgnoreList>");
	static const auto LogCentralIgnoreListEnd = TEXT("</LogCentralIgnoreList>");
	static const TMap<FString, FString> LogCentralItemsToAdd = {
		{ TEXT("MediaDuplicated"), TEXT("<IgnoreItem MessageId=\"MediaDuplicated\"/>") },
		{ TEXT("MediaNotFound"), TEXT("<IgnoreItem MessageId=\"MediaNotFound\"/>") }
	};

	static const TArray<PropertyToChange> PropertiesOnlyForEventBasedWorkflow = {
		{ TEXT("GenerateMainSoundBank"), TEXT("False"), TEXT("<Property Name=\"GenerateMainSoundBank\" Type=\"bool\" Value=\"False\"/>") },
		{ TEXT("GenerateSoundBankXML"), TEXT("False"), TEXT("<Property Name=\"GenerateSoundBankXML\" Type=\"bool\" Value=\"False\"/>") },
	};

	static const TCHAR* CopyStreamedFilesToRemove[] = {
		TEXT("\"$(CopyStreamedFilesExePath)\" -info \"$(InfoFilePath)\" -outputpath \"$(SoundBankPath)\" -banks \"$(SoundBankListAsTextFile)\" -languages \"$(LanguageList)\""),
		TEXT("\"$(WwiseExePath)\\CopyStreamedFiles.exe\" -info \"$(InfoFilePath)\" -outputpath \"$(SoundBankPath)\" -banks \"$(SoundBankList)\" -languages \"$(LanguageList)\""),
		TEXT("\"$(WwiseExePath)\\CopyStreamedFiles.exe\" -info \"$(InfoFilePath)\" -outputpath \"$(SoundBankPath)\" -banks \"$(SoundBankListAsTextFile)\" -languages \"$(LanguageList)\""),
	};

	bool modified = Super::AkAssetManagementManager_ModifyProjectSettings(ProjectContent);

	// Handle LogCentralIgnoreList
	int32 logCentralIgnoreListPosition = ProjectContent.Find(LogCentralIgnoreListBegin);
	if (logCentralIgnoreListPosition != -1)
	{
		int32 endLogCentralIgnoreListPosition = ProjectContent.Find(LogCentralIgnoreListEnd);

		int32 insertPosition = logCentralIgnoreListPosition + FPlatformString::Strlen(LogCentralIgnoreListBegin);

		for (auto itemToAdd : LogCentralItemsToAdd)
		{
			auto foundPosition = ProjectContent.Find(itemToAdd.Key, ESearchCase::IgnoreCase, ESearchDir::FromStart, insertPosition);
			if (foundPosition == -1 || foundPosition > endLogCentralIgnoreListPosition )
			{
				ProjectContent.InsertAt(insertPosition, FString::Printf(TEXT("\n\t\t\t\t%s"), *itemToAdd.Value));
				modified = true;
			}
		}
	}
	else
	{
		int32 environmentalSettingsEndPosition = ProjectContent.Find(EnvironmentalSettingsEnd);
		if (environmentalSettingsEndPosition != -1)
		{
			int32 insertPosition = environmentalSettingsEndPosition + FCString::Strlen(EnvironmentalSettingsEnd);

			FString textToInsert = FString::Printf(TEXT("\n\t\t\t%s"), LogCentralIgnoreListBegin);
			for (auto itemToAdd : LogCentralItemsToAdd)
			{
				textToInsert.Append(FString::Printf(TEXT("\n\t\t\t\t%s"), *itemToAdd.Value));
			}
			textToInsert.Append(FString::Printf(TEXT("\n\t\t\t%s"), LogCentralIgnoreListEnd));

			ProjectContent.InsertAt(insertPosition, textToInsert);
			modified = true;
		}
	}

	modified |= InsertProperties(PropertiesOnlyForEventBasedWorkflow, ProjectContent);

	for (auto toRemove : CopyStreamedFilesToRemove)
	{
		if (ProjectContent.Contains(toRemove))
		{
			ProjectContent.ReplaceInline(toRemove, TEXT(""));
			modified = true;
		}
	}

	return modified;
}

// AkAssetDatabase
FString AkEventBasedToolBehavior::AkAssetDatabase_GetInitBankPackagePath() const
{
	return AkUnrealHelper::GetBaseAssetPackagePath();
}

bool AkEventBasedToolBehavior::AkAssetDatabase_ValidateAssetId(FGuid& outId)
{
	return outId.IsValid();
}

bool AkEventBasedToolBehavior::AkAssetDatabase_Remove(AkAssetDatabase* Instance, const FAssetData& AssetData)
{
	auto Id = AssetData.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));
	if (!Id.IsValid())
	{
		return false;
	}

	auto currentObjectIt = Instance->AudioTypeMap.Find(Id);
	if (currentObjectIt)
	{
		auto objectPath = currentObjectIt->ObjectPath.ToString();

		if (objectPath != AssetData.ObjectPath.ToString())
		{
			return false;
		}
	}

	auto assetKlass = AssetData.GetClass();

	if (assetKlass->IsChildOf<UAkAcousticTexture>())
	{
		Instance->AcousticTextureMap.Remove(Id);
	}
	else if (assetKlass->IsChildOf<UAkAudioEvent>())
	{
		Instance->EventMap.Remove(Id);
	}
	else if (assetKlass->IsChildOf<UAkAuxBus>())
	{
		Instance->AuxBusMap.Remove(Id);
	}
	else if (assetKlass->IsChildOf<UAkGroupValue>())
	{
		Instance->GroupValueMap.Remove(Id);
	}
	else if (assetKlass->IsChildOf<UAkTrigger>())
	{
		Instance->TriggerMap.Remove(Id);
	}
	else if (assetKlass->IsChildOf<UAkRtpc>())
	{
		Instance->RtpcMap.Remove(Id);
	}
	else if (assetKlass->IsChildOf<UAkAudioBank>())
	{
		Instance->BankMap.Remove(Id);
	}
	else if (assetKlass->IsChildOf<UAkFolder>())
	{
		Instance->FolderMap.Remove(Id);
	}
	else if (assetKlass->IsChildOf<UAkInitBank>())
	{
		Instance->InitBank = nullptr;
	}
	else
	{
		return false;
	}

	return Instance->AudioTypeMap.Remove(Id) > 0;
}

// AkSoundDataBuilder
bool AkEventBasedToolBehavior::AkSoundDataBuilder_GetBankName(AkSoundDataBuilder* Instance, UAkAudioBank* Bank, const TSet<FString>& BanksToGenerate, FString& bankName)
{
	bankName = AkUnrealHelper::GuidToBankName(Bank->ID);
	return BanksToGenerate.Num() == 0 || BanksToGenerate.Contains(Bank->GetFName().ToString());
}

// CookAkSoundDataTask
TSharedPtr<AkSoundDataBuilder, ESPMode::ThreadSafe> AkEventBasedToolBehavior::CookAkSoundDataTask_CreateBuilder(const AkSoundDataBuilder::InitParameters& InitParameters)
{
	if (FAkWaapiClient::IsProjectLoaded())
	{
		return MakeShared<WaapiAkSoundDataBuilder, ESPMode::ThreadSafe>(InitParameters);
	}

	return MakeShared<WwiseConsoleAkSoundDataBuilder, ESPMode::ThreadSafe>(InitParameters);
}

// WwiseConsoleAkSoundDataBuilder
FString AkEventBasedToolBehavior::WwiseConsoleAkSoundDataBuilder_AudioBankEventIncludes() const
{
	return TEXT("\"\tEvent\tStructure");
}

FString AkEventBasedToolBehavior::WwiseConsoleAkSoundDataBuilder_AudioBankAuxBusIncludes() const
{
	return TEXT("\"\tStructure");
}

// AkAssetFactory
bool AkEventBasedToolBehavior::AkAssetFactory_ValidNewAssetPath(FName Name, const FString& AssetPath, const UClass* AssetClass) const
{
	if (AssetClass->IsChildOf<UAkAudioBank>())
	{
		return true;
	}

	auto baseWwiseTypePath = FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), AkAssetDatabase::GetBaseFolderForAssetType(AssetClass));

	if (!AssetPath.StartsWith(baseWwiseTypePath, ESearchCase::IgnoreCase))
	{
		const FFormatNamedArguments Args
		{
			{ TEXT("ObjectName"), FText::FromName(Name) },
			{ TEXT("ClassName"), FText::FromString(AssetClass->GetName()) },
			{ TEXT("PathName"), FText::FromString(AssetPath) },
			{ TEXT("WwisePath"), FText::FromString(baseWwiseTypePath) }
		};

		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetFactory", "CannotCreateAssetInPath", "Cannot create new asset '{ObjectName}' of class '{ClassName}' in path '{PathName}'. Please place your asset under the '{WwisePath}' folder."), Args));
		return false;
	}

	return true;
}
