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

#include "AkAssetManagementManager.h"

#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioStyle.h"
#include "AkSettings.h"
#include "AkSettingsPerUser.h"
#include "AkUnrealHelper.h"
#include "AkWaapiClient.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "AssetManagement/CreateAkAssetsVisitor.h"
#include "AssetMigrationVisitor.h"
#include "ContentBrowserModule.h"
#include "Core/Public/Modules/ModuleManager.h"
#include "DirectoryWatcher/Public/DirectoryWatcherModule.h"
#include "DragAndDrop/AssetDragDropOp.h"
#include "Editor.h"
#include "Framework/Notifications/NotificationManager.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "ToolBehavior/AkToolBehavior.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "WwisePicker/WwiseAssetDragDropOp.h"
#include "UnrealEd/Public/ObjectTools.h"

#define LOCTEXT_NAMESPACE "AkAudio"

void AkAssetManagementManager::Init()
{
	auto wwiseProjectPath = AkUnrealHelper::GetWwiseProjectPath();
	if (FPaths::FileExists(wwiseProjectPath))
	{
		wwiseProjectFolder = FPaths::GetPath(wwiseProjectPath);

		auto& DirectoryWatcherModule = FModuleManager::LoadModuleChecked<FDirectoryWatcherModule>(TEXT("DirectoryWatcher"));
		DirectoryWatcherModule.Get()->RegisterDirectoryChangedCallback_Handle(
			wwiseProjectFolder
			, IDirectoryWatcher::FDirectoryChanged::CreateRaw(this, &AkAssetManagementManager::onWwiseDirectoryChanged)
			, wwiseDirectoryChangedHandle
			, IDirectoryWatcher::WatchOptions::IncludeDirectoryChanges
		);
	}

	waapiAssetSync.Init();

	FAssetViewDragAndDropExtender::FOnDropDelegate DropDelegate = FAssetViewDragAndDropExtender::FOnDropDelegate::CreateRaw(this, &AkAssetManagementManager::onAssetViewDrop);
	FAssetViewDragAndDropExtender::FOnDragOverDelegate DragOverDelegate = FAssetViewDragAndDropExtender::FOnDragOverDelegate::CreateRaw(this, &AkAssetManagementManager::onAssetViewDragOver);
	FAssetViewDragAndDropExtender::FOnDragLeaveDelegate DragLeaveDelegate = FAssetViewDragAndDropExtender::FOnDragLeaveDelegate::CreateRaw(this, &AkAssetManagementManager::onAssetViewDragLeave);
	dragDropExtender = MakeUnique<FAssetViewDragAndDropExtender>(DropDelegate, DragOverDelegate, DragLeaveDelegate);

	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetViewDragAndDropExtender>& AssetViewDragAndDropExtenders = ContentBrowserModule.GetAssetViewDragAndDropExtenders();
	AssetViewDragAndDropExtenders.Add(*(dragDropExtender.Get()));

	isInited = true;
}

void AkAssetManagementManager::Uninit()
{
	isInited = false;

	waapiAssetSync.Uninit();

	if (wwiseDirectoryChangedHandle.IsValid())
	{
		auto& DirectoryWatcherModule = FModuleManager::LoadModuleChecked<FDirectoryWatcherModule>(TEXT("DirectoryWatcher"));
		DirectoryWatcherModule.Get()->UnregisterDirectoryChangedCallback_Handle(wwiseProjectFolder, wwiseDirectoryChangedHandle);
	}

	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetViewDragAndDropExtender>& AssetViewDragAndDropExtenders = ContentBrowserModule.GetAssetViewDragAndDropExtenders();
	for (int32 i = 0; i < AssetViewDragAndDropExtenders.Num(); i++)
	{
		if (AssetViewDragAndDropExtenders[i].OnDropDelegate.IsBoundToObject(this))
		{
			AssetViewDragAndDropExtenders.RemoveAt(i);
		}
	}
}

void AkAssetManagementManager::DoAssetSynchronization()
{
	auto start = FPlatformTime::Cycles64();
	if (isInited)
	{
		waapiAssetSync.Uninit();
	}

	CreateAkAssetsVisitor visitor;
	workUnitParser.SetVisitor(&visitor);

	if (onlyParsePhysicalFolders) 
	{
		workUnitParser.ParsePhysicalFolders();
	}

	else
	{
		workUnitParser.ForceParse();
	}
	workUnitParser.SetVisitor(nullptr);

	if (isInited)
	{
		waapiAssetSync.Init();
	}

	auto end = FPlatformTime::Cycles64();

	UE_LOG(LogAkSoundData, Display, TEXT("Wwise Asset Synchronization took %f seconds."), FPlatformTime::ToSeconds64(end - start));
}

void AkAssetManagementManager::DoAssetMigration()
{
	ClearSoundBanksForMigration();

	if (!isInited)
	{
		Init();
	}

	waapiAssetSync.Uninit();

	AssetMigrationVisitor visitor;
	workUnitParser.SetVisitor(&visitor);
	workUnitParser.ForceParse();
	workUnitParser.SetVisitor(nullptr);

	waapiAssetSync.Init();

	FNotificationInfo Info(LOCTEXT("AkAssetManagementManager", "Wwise sound data migration completed!"));

	Info.Image = FAkAudioStyle::GetBrush(TEXT("AudiokineticTools.AkPickerTabIcon"));
	Info.bFireAndForget = true;
	Info.FadeOutDuration = 0.6f;
	Info.ExpireDuration = 4.6f;
	FSlateNotificationManager::Get().AddNotification(Info);

	GEditor->PlayEditorSound(TEXT("/Engine/EditorSounds/Notifications/CompileSuccess_Cue.CompileSuccess_Cue"));
}

void AkAssetManagementManager::ClearSoundBanksForMigration()
{
	auto soundBankDirectory = AkUnrealHelper::GetSoundBankDirectory();

	TArray<FString> foundFiles;

	auto& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	platformFile.FindFilesRecursively(foundFiles, *soundBankDirectory, TEXT(".bnk"));
	platformFile.FindFilesRecursively(foundFiles, *soundBankDirectory, TEXT(".json"));

	if (foundFiles.Num() > 0)
	{
		platformFile.DeleteDirectoryRecursively(*AkUnrealHelper::GetSoundBankDirectory());
	}
}

void AkAssetManagementManager::ModifyProjectSettings()
{
	// This whole hack is because Unreal XML classes doesn't
	// handle <!CDATA[]> which the Wwise project file use.
	// Doing it the dirty way instead.
	auto projectPath = AkUnrealHelper::GetWwiseProjectPath();
	FString projectContent;
	if (FFileHelper::LoadFileToString(projectContent, *projectPath))
	{
		bool modified = AkToolBehavior::Get()->AkAssetManagementManager_ModifyProjectSettings(projectContent);

		if (modified)
		{
			FFileHelper::SaveStringToFile(projectContent, *projectPath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
		}
	}
}

void AkAssetManagementManager::onWwiseDirectoryChanged(const TArray<FFileChangeData>& ChangedFiles)
{
	if (FAkWaapiClient::IsProjectLoaded())
	{
		return;
	}

	bool doAssetSync = false;
	bool doFolderSync = false;
	for (auto& file : ChangedFiles)
	{
		auto extension = FPaths::GetExtension(file.Filename);
		if (extension == TEXT("wwu"))
		{
			doAssetSync = true;
		}
		else if (extension == TEXT("wproj")) 
		{
			doFolderSync = true;
		}
	}

	if (doAssetSync)
	{
		DoAssetSynchronization();
	}
	else if (doFolderSync)
	{
		onlyParsePhysicalFolders = true;
		DoAssetSynchronization();
		onlyParsePhysicalFolders = false;
	}
}

bool AkAssetManagementManager::onAssetViewDrop(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	return canDrop;
}

bool AkAssetManagementManager::onAssetViewDragOver(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	if (!AkUnrealHelper::IsUsingEventBased() || !GetDefault<UAkSettingsPerUser>()->EnableAutomaticAssetSynchronization)
	{
		canDrop = false;
		return false;
	}

	if (Payload.DragDropOp->IsOfType<FWwiseAssetDragDropOp>())
	{
		canDrop = false;
		return false;
	}

	if (!Payload.DragDropOp->IsOfType<FAssetDragDropOp>())
	{
		canDrop = false;
		return false;
	}

	auto assetDragDrop = static_cast<FAssetDragDropOp*>(Payload.DragDropOp.Get());

	auto& assets = assetDragDrop->GetAssets();

	for (int32 assetIndex = 0; assetIndex < assets.Num(); ++assetIndex)
	{
		auto& assetData = assets[assetIndex];

		for (auto& packagePath : Payload.PackagePaths)
		{
			if (!AkAssetDatabase::Get().CanBeDropped(assetData, packagePath, AkAssetDatabase::CanBeDroppedSource::FromContentBrowser))
			{
				canDrop = false;
				return true;
			}
		}
	}

	canDrop = true;

	return false;
}

bool AkAssetManagementManager::onAssetViewDragLeave(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	canDrop = false;
	return false;
}

#undef LOCTEXT_NAMESPACE
