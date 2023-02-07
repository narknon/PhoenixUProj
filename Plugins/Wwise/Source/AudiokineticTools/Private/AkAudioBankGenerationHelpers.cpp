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


/*------------------------------------------------------------------------------------
	AkAudioBankGenerationHelpers.cpp: Wwise Helpers to generate banks from the editor and when cooking.
------------------------------------------------------------------------------------*/

#include "AkAudioBankGenerationHelpers.h"

#include "AkAudioBank.h"
#include "AkAudioType.h"
#include "AkMediaAsset.h"
#include "AkSettings.h"
#include "AkSettingsPerUser.h"
#include "AkUnrealHelper.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "Editor/UnrealEd/Public/ObjectTools.h"
#include "HAL/FileManager.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "MainFrame/Public/Interfaces/IMainFrameModule.h"
#include "Misc/Paths.h"
#include "Misc/ScopedSlowTask.h"
#include "Slate/Public/Framework/Application/SlateApplication.h"
#include "Slate/Public/Widgets/Input/SButton.h"
#include "Slate/Public/Widgets/Layout/SSpacer.h"
#include "Slate/Public/Widgets/Text/STextBlock.h"
#include "SlateCore/Public/Widgets/SBoxPanel.h"
#include "SlateCore/Public/Widgets/SWindow.h"
#include "ToolBehavior/AkToolBehavior.h"
#include "UI/SClearSoundData.h"
#include "UObject/UObjectIterator.h"
#include "WwiseProject/WwiseProjectInfo.h"

#define LOCTEXT_NAMESPACE "AkAudio"

DEFINE_LOG_CATEGORY(LogAkSoundData);

namespace AkAudioBankGenerationHelper
{
	FString GetWwiseConsoleApplicationPath()
	{
		const UAkSettingsPerUser* AkSettingsPerUser = GetDefault<UAkSettingsPerUser>();
		FString ApplicationToRun;
		ApplicationToRun.Empty();

		if (AkSettingsPerUser)
		{
#if PLATFORM_WINDOWS
			ApplicationToRun = AkSettingsPerUser->WwiseWindowsInstallationPath.Path;
#else
			ApplicationToRun = AkSettingsPerUser->WwiseMacInstallationPath.FilePath;
#endif
			if (FPaths::IsRelative(ApplicationToRun))
			{
				ApplicationToRun = FPaths::ConvertRelativePathToFull(AkUnrealHelper::GetProjectDirectory(), ApplicationToRun);
			}
			if (!(ApplicationToRun.EndsWith(TEXT("/")) || ApplicationToRun.EndsWith(TEXT("\\"))))
			{
				ApplicationToRun += TEXT("/");
			}

#if PLATFORM_WINDOWS
			if (FPaths::FileExists(ApplicationToRun + TEXT("Authoring/x64/Release/bin/WwiseConsole.exe")))
			{
				ApplicationToRun += TEXT("Authoring/x64/Release/bin/WwiseConsole.exe");
			}
			else
			{
				ApplicationToRun += TEXT("Authoring/Win32/Release/bin/WwiseConsole.exe");
			}
			ApplicationToRun.ReplaceInline(TEXT("/"), TEXT("\\"));
#elif PLATFORM_MAC
			ApplicationToRun += TEXT("Contents/Tools/WwiseConsole.sh");
			ApplicationToRun = TEXT("\"") + ApplicationToRun + TEXT("\"");
#endif
		}

		return ApplicationToRun;
	}

	void CreateGenerateSoundDataWindow(TArray<TWeakObjectPtr<UAkAudioBank>>* SoundBanks, bool ProjectSave)
	{
		auto& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		if (AssetRegistryModule.Get().IsLoadingAssets())
		{
			return;
		}

		TSharedRef<SWindow> WidgetWindow = SNew(SWindow)
			.Title(LOCTEXT("AkAudioGenerateSoundData", "Generate Sound Data"))
			.ClientSize(FVector2D(600.f, 332.f))
			.SupportsMaximize(false).SupportsMinimize(false)
			.SizingRule(ESizingRule::FixedSize)
			.FocusWhenFirstShown(true);

		if (!AkToolBehavior::Get()->CreateSoundDataWidget(WidgetWindow, SoundBanks, ProjectSave))
		{
			return;
		}

		// This creates a windows that blocks the rest of the UI. You can only interact with the "Generate SoundBanks" window.
		// If you choose to use this, comment the rest of the function.
		//GEditor->EditorAddModalWindow(WidgetWindow);

		// This creates a window that still allows you to interact with the rest of the editor. If there is an attempt to delete
		// a UAkAudioBank (from the content browser) while this window is opened, the editor will generate a (cryptic) error message
		TSharedPtr<SWindow> ParentWindow;
		if (FModuleManager::Get().IsModuleLoaded("MainFrame"))
		{
			IMainFrameModule& MainFrame = FModuleManager::GetModuleChecked<IMainFrameModule>("MainFrame");
			ParentWindow = MainFrame.GetParentWindow();
		}

		if (ParentWindow.IsValid())
		{
			// Parent the window to the main frame 
			FSlateApplication::Get().AddWindowAsNativeChild(WidgetWindow, ParentWindow.ToSharedRef());
		}
		else
		{
			// Spawn new window
			FSlateApplication::Get().AddWindow(WidgetWindow);
		}
	}

	void CreateClearSoundDataWindow()
	{
		auto& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		if (AssetRegistryModule.Get().IsLoadingAssets())
		{
			return;
		}

		TSharedRef<SWindow> WidgetWindow = SNew(SWindow)
			.Title(LOCTEXT("AkAudioGenerateSoundData", "Clear Sound Data"))
			.SupportsMaximize(false).SupportsMinimize(false)
			.SizingRule(ESizingRule::Autosized)
			.FocusWhenFirstShown(true);

		TSharedRef<SClearSoundData> WindowContent = SNew(SClearSoundData);

		// Add our SClearSoundData to the window
		WidgetWindow->SetContent(WindowContent);

		// Set focus to our SClearSoundData widget, so our keyboard keys work right off the bat
		WidgetWindow->SetWidgetToFocusOnActivate(WindowContent);

		TSharedPtr<SWindow> ParentWindow;
		if (FModuleManager::Get().IsModuleLoaded("MainFrame"))
		{
			IMainFrameModule& MainFrame = FModuleManager::GetModuleChecked<IMainFrameModule>("MainFrame");
			ParentWindow = MainFrame.GetParentWindow();
		}

		if (ParentWindow.IsValid())
		{
			// Parent the window to the main frame 
			FSlateApplication::Get().AddWindowAsNativeChild(WidgetWindow, ParentWindow.ToSharedRef());
		}
		else
		{
			// Spawn new window
			FSlateApplication::Get().AddWindow(WidgetWindow);
		}
	}

	void DoClearSoundData(AkSoundDataClearFlags ClearFlags)
	{
		if (!AkUnrealHelper::IsUsingEventBased())
		{
			return;
		}

		auto& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

		WwiseProjectInfo wwiseProjectInfo;
		wwiseProjectInfo.Parse();

		auto start = FPlatformTime::Cycles64();

		FScopedSlowTask SlowTask(0.f, LOCTEXT("AK_ClearingSoundData", "Clearing Wwise Sound Data..."));
		SlowTask.MakeDialog();

		TArray<FString> clearCommands;

		if ((ClearFlags & AkSoundDataClearFlags::AssetData) == AkSoundDataClearFlags::AssetData)
		{
			TArray<FAssetData> AssetsToDelete;
			if (FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get())
			{
				AkAudioDevice->UnloadAllSoundData();
			}

			TArray<FAssetData> allAudioTypeAssets;
			AssetRegistryModule.Get().GetAssetsByClass(UAkAudioType::StaticClass()->GetFName(), allAudioTypeAssets, true);
			for (auto& assetData : allAudioTypeAssets)
			{
				SlowTask.EnterProgressFrame(0.f, FText::FormatOrdered(LOCTEXT("AK_ClearAssetData", "Clearing data from asset {0}"), FText::FromName(assetData.AssetName)));
				if (auto* akAssetInstance = Cast<UAkAudioType>(assetData.GetAsset()))
				{
					akAssetInstance->Reset(AssetsToDelete);
				}
			}

			TArray<FAssetData> allMediaAssets;
			AssetRegistryModule.Get().GetAssetsByClass(UAkMediaAsset::StaticClass()->GetFName(), allMediaAssets, true);

			for (auto& mediaData : allMediaAssets)
			{
				SlowTask.EnterProgressFrame(0.f, FText::FormatOrdered(LOCTEXT("AK_ClearAssetData", "Clearing data from asset {0}"), FText::FromName(mediaData.AssetName)));

				if (auto mediaInstance = Cast<UAkMediaAsset>(mediaData.GetAsset()))
				{
					mediaInstance->Reset();
				}
			}

			TArray<FAssetData> allPlatformData;
			AssetRegistryModule.Get().GetAssetsByClass(UAkAssetPlatformData::StaticClass()->GetFName(), allPlatformData);

			for (auto& platformData : allPlatformData)
			{
				SlowTask.EnterProgressFrame(0.f, FText::FormatOrdered(LOCTEXT("AK_ClearAssetData", "Clearing data from asset {0}"), FText::FromName(platformData.AssetName)));

				if (auto platformInstance = Cast<UAkAssetPlatformData>(platformData.GetAsset()))
				{
					platformInstance->Reset();
				}
			}

			clearCommands.Add(TEXT("Asset Data"));

			const UAkSettings* AkSettings = GetDefault<UAkSettings>();
			if ((ClearFlags & AkSoundDataClearFlags::DeleteLocalizedPlatformData) == AkSoundDataClearFlags::DeleteLocalizedPlatformData)
			{
				ObjectTools::DeleteAssets(AssetsToDelete, true);
			}
		}

		if ((ClearFlags & AkSoundDataClearFlags::SoundBankInfoCache) == AkSoundDataClearFlags::SoundBankInfoCache)
		{
			SlowTask.EnterProgressFrame(0.f, LOCTEXT("AK_ClearSoundBankInfoCache", "Clearing SoundBankInfoCache.dat"));

			auto soundBankInfoCachePath = FPaths::Combine(wwiseProjectInfo.GetCacheDirectory(), TEXT("SoundBankInfoCache.dat"));
			FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*soundBankInfoCachePath);

			clearCommands.Add(TEXT("SoundBank Info Cache"));
		}

		if ((ClearFlags & AkSoundDataClearFlags::MediaCache) == AkSoundDataClearFlags::MediaCache)
		{
			auto cacheFolderPath = wwiseProjectInfo.GetCacheDirectory();
			TArray<FString> foldersInCache;

			auto& platformFile = FPlatformFileManager::Get().GetPlatformFile();
			platformFile.IterateDirectory(*cacheFolderPath, [&foldersInCache](const TCHAR* Path, bool IsDir) {
				if (IsDir)
				{
					foldersInCache.Add(Path);
				}

				return true;
			});

			for (auto& folder : foldersInCache)
			{
				SlowTask.EnterProgressFrame(0.f, FText::FormatOrdered(LOCTEXT("AK_ClearAssetData", "Clearing media cache {0}"), FText::FromString(folder)));

				platformFile.DeleteDirectoryRecursively(*folder);
			}

			clearCommands.Add(TEXT("Media Cache"));
		}

		if ((ClearFlags & AkSoundDataClearFlags::ExternalSource) == AkSoundDataClearFlags::ExternalSource)
		{
			auto externalSourceFolder = AkUnrealHelper::GetExternalSourceDirectory();
			TArray<FString> foldersInExternalSource;

			auto& platformFile = FPlatformFileManager::Get().GetPlatformFile();
			platformFile.IterateDirectory(*externalSourceFolder, [&foldersInExternalSource](const TCHAR* Path, bool IsDir) {
				if (IsDir)
				{
					foldersInExternalSource.Add(Path);
				}

				return true;
			});

			for (auto& folder : foldersInExternalSource)
			{
				SlowTask.EnterProgressFrame(0.f, FText::FormatOrdered(LOCTEXT("AK_ClearAssetData", "Clearing external source cache folder {0}"), FText::FromString(folder)));

				platformFile.DeleteDirectoryRecursively(*folder);
			}

			clearCommands.Add(TEXT("External Source"));
		}

		if ((ClearFlags & AkSoundDataClearFlags::OrphanMedia) == AkSoundDataClearFlags::OrphanMedia)
		{
			TArray<FAssetData> mediaToDelete;

			TArray<FAssetData> allMediaAssets;
			AssetRegistryModule.Get().GetAssetsByClass(UAkMediaAsset::StaticClass()->GetFName(), allMediaAssets);
			AssetRegistryModule.Get().GetAssetsByClass(UAkLocalizedMediaAsset::StaticClass()->GetFName(), allMediaAssets);

			for (auto& mediaData : allMediaAssets)
			{
				SlowTask.EnterProgressFrame(0.f, FText::FormatOrdered(LOCTEXT("AK_ClearAssetData", "Checking if media asset {0} is an orphan"), FText::FromName(mediaData.AssetName)));

				if (mediaData.GetClass()->IsChildOf<UAkExternalMediaAsset>())
				{
					continue;
				}

				TArray<FName> dependencies;
#if UE_4_26_OR_LATER
				AssetRegistryModule.Get().GetReferencers(mediaData.PackageName, dependencies, UE::AssetRegistry::EDependencyCategory::All);
#else
				AssetRegistryModule.Get().GetReferencers(mediaData.PackageName, dependencies, EAssetRegistryDependencyType::All);
#endif
				if (dependencies.Num() == 0)
				{
					mediaToDelete.Add(mediaData);
				}
			}

			if (mediaToDelete.Num() > 0)
			{
				clearCommands.Add(TEXT("Orphan Media"));
				ObjectTools::DeleteAssets(mediaToDelete, true);
			}
		}

		if ((ClearFlags & AkSoundDataClearFlags::OrphanAssetData) == AkSoundDataClearFlags::OrphanAssetData)
		{
			TArray<FAssetData> AssetDataToDelete;
			TArray<FAssetData> AllAssetData;
			AssetRegistryModule.Get().GetAssetsByClass(UAkAssetPlatformData::StaticClass()->GetFName(), AllAssetData);

			for (auto& AssetData : AllAssetData)
			{
				SlowTask.EnterProgressFrame(0.f, FText::FormatOrdered(LOCTEXT("AK_ClearAssetData", "Checking if asset {0} is an orphan"), FText::FromName(AssetData.AssetName)));


				TArray<FName> dependencies;
#if UE_4_26_OR_LATER
				AssetRegistryModule.Get().GetReferencers(AssetData.PackageName, dependencies, UE::AssetRegistry::EDependencyCategory::All);
#else
				AssetRegistryModule.Get().GetReferencers(AssetData.PackageName, dependencies, EAssetRegistryDependencyType::All);
#endif
				if (dependencies.Num() == 0)
				{
					AssetDataToDelete.Add(AssetData);
				}
			}

			if (AssetDataToDelete.Num() > 0)
			{
				clearCommands.Add(TEXT("Orphan Asset Data"));
				ObjectTools::DeleteAssets(AssetDataToDelete, true);
			}
		}

		auto end = FPlatformTime::Cycles64();

		UE_LOG(LogAkSoundData, Display, TEXT("Clear Wwise Sound Data(%s) took %f seconds."), *FString::Join(clearCommands, TEXT(", ")), FPlatformTime::ToSeconds64(end - start));
	}
}

#undef LOCTEXT_NAMESPACE
