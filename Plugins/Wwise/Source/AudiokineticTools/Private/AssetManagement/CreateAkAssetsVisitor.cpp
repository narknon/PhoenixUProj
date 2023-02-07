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

#include "CreateAkAssetsVisitor.h"

#include "AkAcousticTexture.h"
#include "AkAssetDatabase.h"
#include "AkAudioBank.h"
#include "AkAudioDevice.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkInitBank.h"
#include "AkMediaAsset.h"
#include "AkRtpc.h"
#include "AkSettings.h"
#include "AkStateValue.h"
#include "AkSwitchValue.h"
#include "AkTrigger.h"
#include "AkFolder.h"
#include "AkUnrealHelper.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "AssetTools/Public/AssetToolsModule.h"
#include "Internationalization/Internationalization.h"
#include "Misc/Paths.h"
#include "Misc/ScopedSlowTask.h"
#include "UnrealEd/Public/FileHelpers.h"
#include "UnrealEd/Public/ObjectTools.h"
#include "UnrealEd/Public/PackageTools.h"

#define LOCTEXT_NAMESPACE "AkAudio"

DEFINE_LOG_CATEGORY_STATIC(LogCreateAkAssetsVisitor, Log, All);

void CreateAkAssetsVisitor::OnBeginParse()
{
	doAssetCleanup = true;
}

void CreateAkAssetsVisitor::EnterWorkUnit(const WwiseWorkUnitParser::WorkUnitInfo& wwuInfo, const FString& RelativePath, EWwiseItemType::Type ItemType)
{
	createFolder(wwuInfo.wwuGuid, RelativePath, wwuInfo.wwuName, wwuInfo.isStandalone? EWwiseItemType::StandaloneWorkUnit: EWwiseItemType::NestedWorkUnit);
}

void CreateAkAssetsVisitor::EnterEvent(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createAsset<UAkAudioEvent>(Id, Name, Name, RelativePath);
}

void CreateAkAssetsVisitor::EnterAcousticTexture(const FGuid& Id, const class FXmlNode* CurrentNode, const FString& Name, const FString& RelativePath)
{
	createAsset<UAkAcousticTexture>(Id, Name, Name, RelativePath);
}

void CreateAkAssetsVisitor::EnterAuxBus(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createAsset<UAkAuxBus>(Id, Name, Name, RelativePath);
}

void CreateAkAssetsVisitor::EnterStateGroup(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createFolder(Id, RelativePath, Name, EWwiseItemType::StateGroup);
	currentStateGroupId = Id;
	currentStateGroupName = Name;
}

void CreateAkAssetsVisitor::EnterState(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createAsset<UAkStateValue>(Id, Name, FString::Printf(TEXT("%s-%s"), *currentStateGroupName, *Name), RelativePath, currentStateGroupId);
}

void CreateAkAssetsVisitor::EnterSwitchGroup(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createFolder(Id, RelativePath, Name, EWwiseItemType::SwitchGroup);
	currentSwitchGroupId = Id;
	currentSwitchGroupName = Name;
}

void CreateAkAssetsVisitor::EnterSwitch(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createAsset<UAkSwitchValue>(Id, Name, FString::Printf(TEXT("%s-%s"), *currentSwitchGroupName, *Name), RelativePath, currentSwitchGroupId);
}

void CreateAkAssetsVisitor::EnterGameParameter(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createAsset<UAkRtpc>(Id, Name, Name, RelativePath);
}

void CreateAkAssetsVisitor::EnterTrigger(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createAsset<UAkTrigger>(Id, Name, Name, RelativePath);
}

void CreateAkAssetsVisitor::EnterFolderOrBus(const FGuid& Id, const FString& Name, const FString& RelativePath, EWwiseItemType::Type ItemType)
{
	createFolder(Id, RelativePath, Name, ItemType);
}

void CreateAkAssetsVisitor::End()
{
	auto& assetDatabase = AkAssetDatabase::Get();

	if (auto* InitBank = assetDatabase.InitBank)
	{
		if (auto Outermost = InitBank->GetOutermost())
		{
			if (Outermost->IsDirty())
			{
				packagesToSave.Add(Outermost);
			}
		}
	}


	if (packagesToSave.Num() > 0)
	{
		FScopedSlowTask SlowTask(0.f, LOCTEXT("AK_SaveNewAkAssets", "Saving new sound data assets..."));
		SlowTask.MakeDialog();
		UEditorLoadingAndSavingUtils::SavePackages(packagesToSave, true);
	}

	if (doAssetCleanup)
	{
		TArray<FAssetData> assetDataToDelete;
		{
			FScopeLock autoLock(&assetDatabase.AudioTypeMap.CriticalSection);

			for (auto& typeEntry : assetDatabase.AudioTypeMap.TypeMap)
			{
				if (typeEntry.Value.IsValid() && !typeEntry.Value.GetClass()->IsChildOf<UAkInitBank>() && !typeEntry.Value.GetClass()->IsChildOf<UAkAudioBank>() && !foundAssets.Contains(typeEntry.Key))
				{
					assetDataToDelete.Emplace(typeEntry.Value);
					assetDatabase.FillAssetsToDelete(&typeEntry.Value, assetDataToDelete);
				}
			}
		}

		collectExtraAssetsToDelete(assetDataToDelete);

		if (assetDataToDelete.Num() > 0)
		{
			for (const auto& entry : assetDataToDelete)
			{
				if (auto akAudioTypeToDelete = Cast<UAkAudioType>(entry.GetAsset()))
				{
					assetDatabase.Remove(akAudioTypeToDelete);
				}
			}

			ObjectTools::DeleteAssets(assetDataToDelete, true);
		}
	}
}

template<typename AssetType>
void CreateAkAssetsVisitor::createAsset(const FGuid& Id, const FString& Name, const FString& AssetName, const FString& RelativePath, const FGuid& GroupId)
{
	bool hasFoundAsset = false;
	auto assetModified = false;
	auto package = AkAssetDatabase::Get().CreateOrRenameAsset(AssetType::StaticClass(), Id, Name, AssetName, RelativePath, GroupId, AkAssetDatabase::AssetSyncMode::Filesystem, hasFoundAsset, assetModified);

	if (hasFoundAsset)
	{
		foundAssets.Add(Id);
	}

	if (package && package->IsDirty())
	{
		packagesToSave.AddUnique(package);
	}
}


void CreateAkAssetsVisitor::createFolder(const FGuid& Id, const FString& RelativePath, const FString& Name, const  EWwiseItemType::Type ItemType)
{
	auto assetModified = false;
	auto asset = AkAssetDatabase::Get().CreateOrRenameFolder(UAkFolder::StaticClass(), Id, Name, RelativePath, ItemType, AkAssetDatabase::AssetSyncMode::Filesystem, assetModified);
	if (!asset)
		return;
	foundAssets.Add(Id);

	auto package = asset->GetOutermost();
	if (package && package->IsDirty())
	{
		packagesToSave.AddUnique(package);
	}
}


void CreateAkAssetsVisitor::RegisterError(const FString& xmlFilePath, const FString& errorMessage)
{
	doAssetCleanup = false;
	FString versionMessage = TEXT("");
#if !UE_4_26_OR_LATER
	versionMessage = TEXT(" This can be caused by notes included in the work unit file as <Comment> entries. Removing the notes could fix this issue.");
#endif

	UE_LOG(LogCreateAkAssetsVisitor, Error, TEXT("Could not parse the work unit file '<%s>'. Old wwise assets will not be cleaned up after parsing is finished.<%s> \nError message: <%s>"), *xmlFilePath, *versionMessage, *errorMessage);
}

FString CreateAkAssetsVisitor::FindRelativePath(const FString& WorkUnitPath, const FGuid& id, EWwiseItemType::Type ItemType)
{
	if (auto folder = AkAssetDatabase::Get().FolderMap.FindLiveAsset(id))
	{
		return folder->WwiseFolderPath;
	}
	return {};
}

#undef LOCTEXT_NAMESPACE
