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

// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetManagement/GenerateSoundBanksCommandlet.h"

#if WITH_EDITOR
#include "AkAssetManagementManager.h"
#include "AkAudioBank.h"
#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioEvent.h"
#include "AkMediaAsset.h"
#include "AkSettings.h"
#include "AkSettingsPerUser.h"
#include "AkUnrealHelper.h"
#include "AkWaapiClient.h"
#include "AssetManagement/AssetMigrationVisitor.h"
#include "AssetManagement/CreateAkAssetsVisitor.h"
#include "AssetRegistryModule.h"
#include "AssetTools/Public/AssetToolsModule.h"
#include "Containers/Ticker.h"
#include "DirectoryWatcherModule.h"
#include "Editor.h"
#include "Editor/UnrealEd/Public/FileHelpers.h"
#include "Editor/UnrealEd/Public/ObjectTools.h"
#include "Factories/AkAssetFactories.h"
#include "Framework/Application/SlateApplication.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "IDirectoryWatcher.h"
#include "SourceControl/Public/ISourceControlModule.h"
#include "SourceControl/Public/SourceControlHelpers.h"
#include "WwiseConsoleAkSoundDataBuilder.h"
#include "WwiseProject/WwiseProjectInfo.h"
#include "WwiseProject/WwiseWorkUnitParser.h"
#include "ShaderCompiler.h"

#define LOCTEXT_NAMESPACE "AkAudio"
DEFINE_LOG_CATEGORY_STATIC(LogAkSoundDataCommandlet, Log, All);
#endif

static constexpr auto BanksSwitch = TEXT("banks");
static constexpr auto HelpSwitch = TEXT("help");
static constexpr auto LanguagesSwitch = TEXT("languages");
static constexpr auto MigrateSwitch = TEXT("migrate");
static constexpr auto FixupRedirectorsSwitch = TEXT("fixupRedirectors");
static constexpr auto PlatformsSwitch = TEXT("platforms");
static constexpr auto RebuildSwitch = TEXT("rebuild");
static constexpr auto WwiseConsolePathSwitch = TEXT("wwiseConsolePath");
static constexpr auto AutoSubmitSwitch = TEXT("autosubmit");
static constexpr auto CLNumSwitch = TEXT("clnum");
static constexpr auto ForceAssetSyncSwitch = TEXT("forceAssetSync");

UGenerateSoundBanksCommandlet::UGenerateSoundBanksCommandlet()
{
	IsClient = false;
	IsEditor = true;
	IsServer = false;
	LogToConsole = true;

	HelpDescription = TEXT("Commandlet allowing to generate Wwise SoundBanks.");

	HelpParamNames.Add(PlatformsSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Comma separated list of platforms for which SoundBanks will be generated, as specified in the Wwise project. If not specified, SoundBanks will be generated for all platforms."));

	HelpParamNames.Add(LanguagesSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Comma separated list of languages for which SoundBanks will be generated, as specified in the Wwise project. If not specified, SoundBanks will be generated for all platforms."));

	HelpParamNames.Add(BanksSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Comma separated list of SoundBanks to generate. Bank names must correspond to a UAkAudioBank asset in the project. If not specified, all SoundBanks found in project will be generated."));

	HelpParamNames.Add(WwiseConsolePathSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Full path to the Wwise command-line application to use to generate the SoundBanks. If not specified, the path found in the Wwise settings will be used."));

	HelpParamNames.Add(RebuildSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Clear the whole cache folder of the Wwise project to regenerate all of Wwise data"));

	HelpParamNames.Add(MigrateSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Do the first time migration of the project offline."));

	HelpParamNames.Add(FixupRedirectorsSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) When migration is done, fixup the redirectors that were created by moving assets."));

	HelpParamNames.Add(AutoSubmitSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Automatically submit the generated Wwise assets to version control."));

	HelpParamNames.Add(CLNumSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Changelist number to append to the end of the automatic commit message."));

	HelpParamNames.Add(ForceAssetSyncSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Force asset synchronization with Wwise. Will add new assets, and remove deleted ones."));

	HelpParamNames.Add(HelpSwitch);
	HelpParamDescriptions.Add(TEXT("(Optional) Print this help message. This will quit the commandlet immediately."));

	HelpUsage = TEXT("<Editor.exe> <path_to_uproject> -run=GenerateSoundBanks [-platforms=listOfPlatforms] [-languages=listOfLanguages] [-rebuild]");
	HelpWebLink = TEXT("https://www.audiokinetic.com/library/edge/?source=UE4&id=using_features_generatecommandlet.html");
}

void UGenerateSoundBanksCommandlet::PrintHelp() const
{
	UE_LOG(LogAkSoundDataCommandlet, Display, TEXT("%s"), *HelpDescription);
	UE_LOG(LogAkSoundDataCommandlet, Display, TEXT("Usage: %s"), *HelpUsage);
	UE_LOG(LogAkSoundDataCommandlet, Display, TEXT("Parameters:"));
	for (int32 i = 0; i < HelpParamNames.Num(); ++i)
	{
		UE_LOG(LogAkSoundDataCommandlet, Display, TEXT("\t- %s: %s"), *HelpParamNames[i], *HelpParamDescriptions[i]);
	}
	UE_LOG(LogAkSoundDataCommandlet, Display, TEXT("For more information, see %s"), *HelpWebLink);
}

bool IsUnrealEngineExitRequested()
{
#if UE_4_24_OR_LATER
	return IsEngineExitRequested();
#else
	return GIsRequestingExit;
#endif
}

void SetUnrealEngineExitRequestedToTrue()
{
#if UE_4_24_OR_LATER
	RequestEngineExit(TEXT("Commandlet is done"));
#else
	GIsRequestingExit = true;
#endif
}

void ImportExternalSources()
{
	auto& platformFile = FPlatformFileManager::Get().GetPlatformFile();

	auto externalSourceDirectory = AkUnrealHelper::GetExternalSourceDirectory();
	TArray<FString> externalSources;
	platformFile.FindFilesRecursively(externalSources, *externalSourceDirectory, TEXT(".wem"));

	auto factory = GetMutableDefault<UAkExternalSourceFactory>();

	auto destPath = ObjectTools::SanitizeObjectPath(AkUnrealHelper::GetExternalSourceAssetPackagePath());

	for (auto& filePath : externalSources)
	{
		auto fileName = FPaths::GetBaseFilename(filePath);
		FString packageName = ObjectTools::SanitizeInvalidChars(FPaths::Combine(destPath, fileName), INVALID_LONGPACKAGE_CHARACTERS);

#if UE_4_26_OR_LATER
		UPackage* package = CreatePackage(*packageName);
#else
		UPackage* package = CreatePackage(nullptr, *packageName);
#endif

		bool dummy = false;
		UObject* Result = factory->ImportObject(UAkExternalMediaAsset::StaticClass(), package, FName(*fileName), RF_Public | RF_Standalone | RF_Transactional, filePath, nullptr, dummy);
		if (Result)
		{
			FAssetRegistryModule::AssetCreated(Result);
			GEditor->BroadcastObjectReimported(Result);
		}
	}
}

int32 UGenerateSoundBanksCommandlet::Main(const FString& Params)
{
	int32 ReturnCode = 0;
#if WITH_EDITOR
	FSlateApplication::Create();

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	ISourceControlModule::Get().GetProvider().Init();

	AkSoundDataBuilder::InitParameters InitParameters;

	TArray<FString> Tokens;
	TArray<FString> Switches;
	TMap<FString, FString> ParamVals;

	ParseCommandLine(*Params, Tokens, Switches, ParamVals);

	if (Switches.Contains(HelpSwitch))
	{
		PrintHelp();
		return 0;
	}

	WwiseProjectInfo wwiseProjectInfo;
	wwiseProjectInfo.Parse();

	if (Switches.Contains(RebuildSwitch) || Switches.Contains(MigrateSwitch))
	{
		FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*wwiseProjectInfo.GetCacheDirectory());
	}

	const FString* PlatformValue = ParamVals.Find(PlatformsSwitch);
	if (PlatformValue)
	{
		TArray<FString> PlatformNames;
		TArray<FString> WrongPlatformNames;
		PlatformValue->ParseIntoArray(PlatformNames, TEXT(","));
		for (FString& name : PlatformNames)
		{
			if (wwiseProjectInfo.GetSupportedPlatforms().FindByPredicate([&name](auto& x) { return x.Name == name; }))
			{
				InitParameters.Platforms.Add(name);
			}
			else
			{
				WrongPlatformNames.Add(name);
			}
		}
		if (WrongPlatformNames.Num() == PlatformNames.Num())
		{
			UE_LOG(LogAkSoundDataCommandlet, Error, TEXT("No given platform is supported by this project."));
		}
		else
		{
			for (auto& name : WrongPlatformNames)
			{
				UE_LOG(LogAkSoundDataCommandlet, Warning, TEXT("Platform %s is not supported by this project."), *name);
			}
		}
	}
	else
	{
		for (auto& platform : wwiseProjectInfo.GetSupportedPlatforms())
		{
			InitParameters.Platforms.Add(platform.Name);
		}
	}

	const FString* LanguagesValue = ParamVals.Find(LanguagesSwitch);
	if (LanguagesValue)
	{
		TArray<FString> LanguagesNames;
		LanguagesValue->ParseIntoArray(LanguagesNames, TEXT(","));
		for (FString& name : LanguagesNames)
		{
			if (auto* languageInfo = wwiseProjectInfo.GetSupportedLanguages().FindByPredicate([&name](auto const& info) { return info.Name == name; }))
			{
				InitParameters.Languages.Add(*languageInfo);
			}
		}
	}
	else
	{
		for (auto& language : wwiseProjectInfo.GetSupportedLanguages())
		{
			InitParameters.Languages.Add(language);
		}
	}

	const FString* BanksValue = ParamVals.Find(BanksSwitch);
	if (BanksValue)
	{
		TArray<FString> banksToGenerate;
		BanksValue->ParseIntoArray(banksToGenerate, TEXT(","));

		InitParameters.BanksToGenerate.Append(banksToGenerate);
	}

	FString wwiseAssetPath = AkUnrealHelper::GetBaseAssetPackagePath();
	
	TArray<FAssetData> BankAssets;
	TArray<FString> PathsToScan;
	PathsToScan.Add(wwiseAssetPath);
	AssetRegistryModule.Get().ScanPathsSynchronous(PathsToScan);

	while (AssetRegistryModule.Get().IsLoadingAssets())
	{
		FPlatformProcess::Sleep(1.f / 60.f);
	}

	TArray<FAssetData> allAssets;
	AssetRegistryModule.Get().GetAssetsByClass(UAkAudioType::StaticClass()->GetFName(), allAssets, true);

	for (auto& assetData : allAssets)
	{
		assetData.GetAsset();
	}

	TUniquePtr<CreateAkAssetsVisitor> assetVisitor;

	if (Switches.Contains(MigrateSwitch))
	{
		assetVisitor = MakeUnique<AssetMigrationVisitor>();
		if (auto akSettings = GetMutableDefault<UAkSettings>())
		{
			akSettings->FixupRedirectorsDuringMigration = Switches.Contains(FixupRedirectorsSwitch);
			akSettings->UseEventBasedPackaging = true;
			akSettings->AskedToUseNewAssetManagement = true;
			AkUnrealHelper::SaveConfigFile(akSettings);

			AkAssetManagementManager::ClearSoundBanksForMigration();
		}
	}
	else
	{
		assetVisitor = MakeUnique<CreateAkAssetsVisitor>();
	}

	bool bAutoSubmit = Switches.Contains(AutoSubmitSwitch);

	FString CommitMessage;
	if (auto akSettings = GetMutableDefault<UAkSettings>())
	{
		CommitMessage = akSettings->CommandletCommitMessage;
	}

	const FString* CLNum = ParamVals.Find(CLNumSwitch);
	if (CLNum)
	{
		CommitMessage += *CLNum;
	}

	AkAssetManagementManager::ModifyProjectSettings();

	auto akSettings = GetMutableDefault<UAkSettings>();
	auto akSettingsPerUser = GetMutableDefault<UAkSettingsPerUser>();
	bool bUsingEBP = akSettings && akSettings->UseEventBasedPackaging;
	bool bDoAssetSync = bUsingEBP && (Switches.Contains(ForceAssetSyncSwitch) || (akSettingsPerUser && akSettingsPerUser->EnableAutomaticAssetSynchronization));

	if (bDoAssetSync)
	{
		WwiseWorkUnitParser workUnitParser;
		workUnitParser.SetVisitor(assetVisitor.Get());
		workUnitParser.Parse();
	}

	auto builder = MakeShared<WwiseConsoleAkSoundDataBuilder, ESPMode::ThreadSafe>(InitParameters);

	if (const FString* overrideWwiseConsolePath = ParamVals.Find(WwiseConsolePathSwitch))
	{
		builder->SetOverrideWwiseConsolePath(*overrideWwiseConsolePath);
	}

	builder->Init();

	auto buildTaskRef = FFunctionGraphTask::CreateAndDispatchWhenReady([builder] {
		builder->DoWork();
	},
	GET_STATID(STAT_TaskGraph_OtherTasks), nullptr, ENamedThreads::AnyThread
	);

	auto externalSourceTaskRef = FFunctionGraphTask::CreateAndDispatchWhenReady([] {
		ImportExternalSources();
	},
		GET_STATID(STAT_TaskGraph_OtherTasks), buildTaskRef, ENamedThreads::GameThread
	);

	auto& directoryWatcherModule = FModuleManager::LoadModuleChecked<FDirectoryWatcherModule>(TEXT("DirectoryWatcher"));
	auto* directoryWatcher = directoryWatcherModule.Get();

	if (!IsUnrealEngineExitRequested())
	{
		// Wait for shaders to stop compiling... This prevents the engine tick to try and show a notification when we have no UI,
		// which leads to a Slate crash.
		while (GShaderCompilingManager->GetNumRemainingJobs() > 0) {
			FPlatformProcess::Sleep(1);
			UE_LOG(LogAkSoundDataCommandlet, Display, TEXT("Waiting for shaders to stop compiling... %d left"), GShaderCompilingManager->GetNumRemainingJobs());
		}

		GIsRunning = true;
		while (GIsRunning && !IsUnrealEngineExitRequested())
		{
			auto deltaTime = FApp::GetDeltaTime();
			GEngine->UpdateTimeAndHandleMaxTickRate();
			GEngine->Tick(deltaTime, false);
			GEngine->TickDeferredCommands();

			directoryWatcher->Tick(deltaTime);

			GFrameCounter++;
			FCoreTickerType::GetCoreTicker().Tick(deltaTime);

			GEngine->DeferredCommands.Empty();

			bool bEmptyGameThreadTasks = !FTaskGraphInterface::Get().IsThreadProcessingTasks(ENamedThreads::GameThread);

			if (bEmptyGameThreadTasks)
			{
				// need to process gamethread tasks at least once a frame no matter what
				FTaskGraphInterface::Get().ProcessThreadUntilIdle(ENamedThreads::GameThread);
			}

			if (externalSourceTaskRef->IsComplete())
			{
				TSet<UPackage*>& PackagesToSave = builder->SaveAssetsBlocking();
				
				if (PackagesToSave.Num() > 0)
				{
					if (USourceControlHelpers::IsEnabled())
					{
						if (akSettings)
						{
							auto PackageFilenames = USourceControlHelpers::PackageFilenames(PackagesToSave.Array());
							TArray<FString> FilesToCheckIn;

							for (auto& filename : PackageFilenames)
							{
								if (!USourceControlHelpers::CheckOutOrAddFile(filename))
								{
									UE_LOG(LogAkSoundDataCommandlet, Error, TEXT("Cannot checkout %s"), *filename);
								}
								else
								{
									FilesToCheckIn.Add(filename);
								}

							}

							if (bAutoSubmit && !USourceControlHelpers::CheckInFiles(FilesToCheckIn, CommitMessage))
							{
								UE_LOG(LogAkSoundDataCommandlet, Error, TEXT("Cannot checkin"));
							}
						}
					}
				}
				else
				{
					UE_LOG(LogAkSoundDataCommandlet, Display, TEXT("No Wwise Sound Data to save."));
				}

				SetUnrealEngineExitRequestedToTrue();
			}

			FPlatformProcess::Sleep(0);
		}
	}
#endif

	return ReturnCode;
}

#undef LOCTEXT_NAMESPACE
