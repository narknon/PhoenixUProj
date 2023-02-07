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

#include "WwiseConsoleAkSoundDataBuilder.h"

#include "AkAudioBank.h"
#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioDevice.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkGroupValue.h"
#include "AkInitBank.h"
#include "AkRtpc.h"
#include "AkTrigger.h"
#include "AkAudioType.h"
#include "AkUnrealHelper.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "Async/Async.h"
#include "Async/ParallelFor.h"
#include "Core/Public/Modules/ModuleManager.h"
#include "DirectoryWatcherModule.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "IDirectoryWatcher.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Misc/ScopeExit.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "ToolBehavior/AkToolBehavior.h"
#include "WwiseProject/WwiseSoundBankInfoCache.h"

DECLARE_CYCLE_STAT(TEXT("AkSoundDataBuilder - Watcher ProcessFile"), STAT_WatcherProcessFile, STATGROUP_AkSoundDataSource);
DECLARE_CYCLE_STAT(TEXT("AkSoundDataBuilder - Fetch Event Platform Data"), STAT_FetchEventPlatformData, STATGROUP_AkSoundDataSource);
DECLARE_CYCLE_STAT(TEXT("AkSoundDataBuilder - Read bank data"), STAT_ReadBankData, STATGROUP_AkSoundDataSource);
DECLARE_CYCLE_STAT(TEXT("AkSoundDataBuilder - Read bank definition file"), STAT_ReadBankDefinitionFile, STATGROUP_AkSoundDataSource);

namespace
{
	constexpr auto AkPluginInfoFileName = TEXT("PluginInfo");
}

WwiseConsoleAkSoundDataBuilder::WwiseConsoleAkSoundDataBuilder(const InitParameters& InitParameter)
: AkSoundDataBuilder(InitParameter)
{
	if (!AkUnrealHelper::IsUsingEventBased())
	{
		 auto AssetDatabaseInitTask = FFunctionGraphTask::CreateAndDispatchWhenReady([this]() {
		 	auto& AssetDatabase = AkAssetDatabase::Get();
		 	AssetDatabase.Clear();
		 	AssetDatabase.Init();
			AssetDatabase.ScanForAkAssets();
		 }, GET_STATID(STAT_WatcherProcessFile), nullptr, ENamedThreads::GameThread);

		 FTaskGraphInterface::Get().WaitUntilTaskCompletes(AssetDatabaseInitTask);
	}
}

WwiseConsoleAkSoundDataBuilder::~WwiseConsoleAkSoundDataBuilder()
{
}

void WwiseConsoleAkSoundDataBuilder::Init()
{
	AkSoundDataBuilder::Init();

	watchDirectory = AkUnrealHelper::GetGeneratedSoundBanksFolder();
	FPaths::NormalizeDirectoryName(watchDirectory);

	if (!platformFile->DirectoryExists(*watchDirectory))
	{
		platformFile->CreateDirectory(*watchDirectory);
	}

	directoryWatcherModule = &FModuleManager::LoadModuleChecked<FDirectoryWatcherModule>(TEXT("DirectoryWatcher"));

	if (!IsRunningCommandlet())
	{
		directoryWatcherModule->Get()->RegisterDirectoryChangedCallback_Handle(
			watchDirectory
			, IDirectoryWatcher::FDirectoryChanged::CreateRaw(this, &WwiseConsoleAkSoundDataBuilder::OnDirectoryWatcher)
			, directoryWatcherDelegateHandle
		);
	}
}

void WwiseConsoleAkSoundDataBuilder::DoWork()
{
	AutoSetIsBuilding autoSetIsBuilding;

	auto now = FDateTime::UtcNow();

	StartTime = FPlatformTime::Cycles64();

	if (!IsRunningCommandlet())
	{
		createNotificationItem();
	}

	if (AkUnrealHelper::IsUsingEventBased())
	{
		LoadAndWaitForAssetToLoad();
	}

	bool WwiseConsoleSuccess = runWwiseConsole();

	if (!IsRunningCommandlet())
	{
		directoryWatcherModule->Get()->UnregisterDirectoryChangedCallback_Handle(watchDirectory, directoryWatcherDelegateHandle);
	}

	FTaskGraphInterface::Get().WaitUntilTasksComplete(AllWatcherTasks);

	FGraphEventArray AllProcessTasks;

	for (auto& currentPlatform : initParameters.Platforms)
	{
		auto FolderToParse = FPaths::Combine(watchDirectory, currentPlatform);

		TArray<FString> FilesToParse;
		platformFile->FindFilesRecursively(FilesToParse, *FolderToParse, TEXT(".bnk"));
		platformFile->FindFilesRecursively(FilesToParse, *FolderToParse, TEXT(".json"));

		for (auto& FullPath : FilesToParse)
		{
			if (!ProcessedPaths.Contains(FullPath))
			{
				AllProcessTasks.Add(FFunctionGraphTask::CreateAndDispatchWhenReady([this, FullPath]() 
				{
					ProcessFile(FullPath, watchDirectory);
				}, GET_STATID(STAT_WatcherProcessFile), nullptr, ENamedThreads::GameThread));
			}
		}
	}

	if (AkUnrealHelper::IsUsingEventBased())
	{
		notifyCookingData();
	}

	FTaskGraphInterface::Get().WaitUntilTasksComplete(AllProcessTasks);

	WrapUpGeneration(WwiseConsoleSuccess, TEXT("WwiseConsole"));
}

void WwiseConsoleAkSoundDataBuilder::OnDirectoryWatcher(const TArray<struct FFileChangeData>& ChangedFiles)
{
	TSet<FString> UniqueFiles;
	for (auto& File : ChangedFiles)
	{
		if (File.Action == FFileChangeData::FCA_Added || File.Action == FFileChangeData::FCA_Modified)
		{
			if (FPaths::GetExtension(File.Filename) == TEXT("json"))
			{
				UniqueFiles.Add(File.Filename);
			}

			if (FPaths::GetExtension(File.Filename) == TEXT("txt"))
			{
				UniqueFiles.Add(FPaths::ChangeExtension(File.Filename, TEXT(".bnk")));
			}
		}
	}

	for (auto& FullPath : UniqueFiles)
	{
		FPaths::NormalizeDirectoryName(FullPath);

		AllWatcherTasks.Add(FFunctionGraphTask::CreateAndDispatchWhenReady([sharedThis = SharedThis(this), FullPath]() 
		{
			sharedThis->ProcessFile(FullPath, sharedThis->watchDirectory);
		}, GET_STATID(STAT_WatcherProcessFile), nullptr, ENamedThreads::GameThread));

		ProcessedPaths.Add(FullPath);
	}
}

bool WwiseConsoleAkSoundDataBuilder::runWwiseConsole()
{
	bool success = true;

	auto cacheFile = AkUnrealHelper::GetWwiseSoundBankInfoCachePath();

	WwiseSoundBankInfoCache infoCache;

	if (FPaths::FileExists(cacheFile))
	{
		infoCache.Load(cacheFile);
	}

	bool isUsingNewAssetManagament = AkUnrealHelper::IsUsingEventBased();

	auto tempDefinitionFile = FPaths::CreateTempFilename(FPlatformProcess::UserTempDir(), TEXT("CookUAkAudioEvent"), TEXT(".txt"));
	ON_SCOPE_EXIT{
		platformFile->DeleteFile(*tempDefinitionFile);
	};

	auto tempBankFile = FPaths::CreateTempFilename(FPlatformProcess::UserTempDir(), TEXT("WwiseConsoleBankList"), TEXT(".txt"));
	ON_SCOPE_EXIT{
		platformFile->DeleteFile(*tempBankFile);
	};

	FString wwiseConsoleCommand = !overrideWwiseConsolePath.IsEmpty() ? overrideWwiseConsolePath : AkAudioBankGenerationHelper::GetWwiseConsoleApplicationPath();

	FString wwiseConsoleArguments;
#if PLATFORM_MAC
	wwiseConsoleArguments = wwiseConsoleCommand + TEXT(" ");
	wwiseConsoleCommand = TEXT("/bin/sh");
#endif
	wwiseConsoleArguments += FString::Printf(TEXT("generate-soundbank \"%s\" --use-stable-guid --import-definition-file \"%s\""),
		*platformFile->ConvertToAbsolutePathForExternalAppForWrite(*AkUnrealHelper::GetWwiseProjectPath()),
		*platformFile->ConvertToAbsolutePathForExternalAppForWrite(*tempDefinitionFile)
	);

	auto generatedSoundBanksPath = AkUnrealHelper::GetGeneratedSoundBanksFolder();

	TSet<FString> platformsToBuild;
	TSet<FString> languagesToBuild;

	for (auto& platform : initParameters.Platforms)
	{
		wwiseConsoleArguments += FString::Printf(TEXT(" --platform \"%s\""), *platform);
		wwiseConsoleArguments += FString::Printf(TEXT(" --soundbank-path %s \"%s\""), *platform, *FPaths::Combine(generatedSoundBanksPath, platform));
		platformsToBuild.Add(platform);
	}

	if (initParameters.SkipLanguages)
	{
		wwiseConsoleArguments += TEXT(" --skip-languages");
	}
	else
	{
		for (auto& language : initParameters.Languages)
		{
			wwiseConsoleArguments += FString::Printf(TEXT(" --language \"%s\""), *language.Name);
			languagesToBuild.Add(language.Name);
		}
	}

	AudioBankInfoMap audioBankInfoMap;

	auto future = Async(EAsyncExecution::TaskGraphMainThread, [this, &audioBankInfoMap, &platformsToBuild, &languagesToBuild, &infoCache] {
		return fillAudioBankInfoMap(audioBankInfoMap, FillAudioBankInfoKind::AssetName, platformsToBuild, languagesToBuild, &infoCache).Replace(TEXT(" "), LINE_TERMINATOR);
	});

	FString BankNamesToGenerate = future.Get();

	if (!isUsingNewAssetManagament && !BankNamesToGenerate.IsEmpty())
	{
		TUniquePtr<IFileHandle> fileWriter(platformFile->OpenWrite(*tempBankFile));
		FTCHARToUTF8 utf8(*BankNamesToGenerate);
		fileWriter->Write(reinterpret_cast<const uint8*>(utf8.Get()), utf8.Length());
		fileWriter->Flush();

		wwiseConsoleArguments += FString::Printf(TEXT(" --bank \"%s\""), *tempBankFile);
	}

	UE_LOG(LogAkSoundData, Display, TEXT("Running %s %s"), *wwiseConsoleCommand, *wwiseConsoleArguments);

	auto& akAssetDatabase = AkAssetDatabase::Get();

	{
		TUniquePtr<IFileHandle> fileWriter(platformFile->OpenWrite(*tempDefinitionFile));

		if (isUsingNewAssetManagament)
		{
			FScopeLock autoEventLock(&akAssetDatabase.EventMap.CriticalSection);

			for (auto& eventMapEntry : akAssetDatabase.EventMap.TypeMap)
			{
				auto eventInstance = Cast<UAkAudioEvent>(eventMapEntry.Value.GetAsset());
				if (eventInstance && !eventInstance->RequiredBank)
				{
					if (initParameters.BanksToGenerate.Num() == 0 || initParameters.BanksToGenerate.Contains(eventInstance->GetFName().ToString()))
					{
						auto bankName = AkUnrealHelper::GuidToBankName(eventMapEntry.Key);
						auto line = bankName + TEXT("\t\"") + eventInstance->GetName() + TEXT("\"\tEvent\tStructure") + LINE_TERMINATOR;
						FTCHARToUTF8 utf8(*line);
						fileWriter->Write(reinterpret_cast<const uint8*>(utf8.Get()), utf8.Length());

						if (eventInstance->NeedsRebuild(platformsToBuild, languagesToBuild, &infoCache))
						{
							prepareRebuild(bankName, generatedSoundBanksPath);
						}
					}
				}
			}
		}

		const auto audioBankEventIncludes = AkToolBehavior::Get()->WwiseConsoleAkSoundDataBuilder_AudioBankEventIncludes();
		const auto audioBankAuxBusIncludes = AkToolBehavior::Get()->WwiseConsoleAkSoundDataBuilder_AudioBankAuxBusIncludes();

		for (auto& audioBankEntry : audioBankInfoMap)
		{
			for (auto& eventEntry : audioBankEntry.Value.Events)
			{
				auto line = audioBankEntry.Key + TEXT("\t\"") + eventEntry + audioBankEventIncludes + LINE_TERMINATOR;
				FTCHARToUTF8 utf8(*line);
				fileWriter->Write(reinterpret_cast<const uint8*>(utf8.Get()), utf8.Length());
			}

			for (auto& auxBusEntry : audioBankEntry.Value.AuxBusses)
			{
				auto line = audioBankEntry.Key + TEXT("\t-AuxBus\t\"") + auxBusEntry + audioBankAuxBusIncludes + LINE_TERMINATOR;
				FTCHARToUTF8 utf8(*line);
				fileWriter->Write(reinterpret_cast<const uint8*>(utf8.Get()), utf8.Length());
			}

			if (isUsingNewAssetManagament && audioBankEntry.Value.NeedsRebuild)
			{
				prepareRebuild(audioBankEntry.Key, generatedSoundBanksPath);
			}
		}

		if (isUsingNewAssetManagament)
		{
			FScopeLock autoAuxBusLock(&akAssetDatabase.AuxBusMap.CriticalSection);

			for (auto& auxBusMapEntry : akAssetDatabase.AuxBusMap.TypeMap)
			{
				auto auxBusInstance = Cast<UAkAuxBus>(auxBusMapEntry.Value.GetAsset());
				if (auxBusInstance && !auxBusInstance->RequiredBank)
				{
					if (initParameters.BanksToGenerate.Num() == 0 || initParameters.BanksToGenerate.Contains(auxBusInstance->GetFName().ToString()))
					{
						auto bankName = AkUnrealHelper::GuidToBankName(auxBusMapEntry.Key);
						auto line = bankName + TEXT("\t-AuxBus\t\"") + auxBusInstance->GetName() + TEXT("\"\tStructure") + LINE_TERMINATOR;
						FTCHARToUTF8 utf8(*line);
						fileWriter->Write(reinterpret_cast<const uint8*>(utf8.Get()), utf8.Length());

						if (auxBusInstance->NeedsRebuild(platformsToBuild, languagesToBuild, &infoCache))
						{
							prepareRebuild(bankName, generatedSoundBanksPath);
						}
					}
				}
			}
		}
		fileWriter->Flush();
	}

	// Create a pipe for the child process's STDOUT.
	int32 ReturnCode = 0;
	void* WritePipe = nullptr;
	void* ReadPipe = nullptr;
	FPlatformProcess::CreatePipe(ReadPipe, WritePipe);
	ON_SCOPE_EXIT {
		FPlatformProcess::ClosePipe(ReadPipe, WritePipe);
	};

	FProcHandle ProcHandle = FPlatformProcess::CreateProc(*wwiseConsoleCommand, *wwiseConsoleArguments, true, true, true, nullptr, 0, nullptr, WritePipe);
	if (ProcHandle.IsValid())
	{
		FString NewLine;
		FPlatformProcess::Sleep(0.1f);
		// Wait for it to finish and get return code
		while (FPlatformProcess::IsProcRunning(ProcHandle))
		{
			NewLine = FPlatformProcess::ReadPipe(ReadPipe);
			if (NewLine.Len() > 0)
			{
				UE_LOG(LogAkSoundData, Display, TEXT("%s"), *NewLine);
				NewLine.Empty();
			}
			FPlatformProcess::Sleep(0.25f);
		}

		NewLine = FPlatformProcess::ReadPipe(ReadPipe);
		if (NewLine.Len() > 0)
		{
			UE_LOG(LogAkSoundData, Display, TEXT("%s"), *NewLine);
		}

		FPlatformProcess::GetProcReturnCode(ProcHandle, &ReturnCode);

		switch (ReturnCode)
		{
		case 2:
			UE_LOG(LogAkSoundData, Warning, TEXT("WwiseConsole completed with warnings."));
			break;
		case 0:
			UE_LOG(LogAkSoundData, Display, TEXT("WwiseConsole successfully completed."));
			break;
		default:
			UE_LOG(LogAkSoundData, Error, TEXT("WwiseConsole failed with error %d."), ReturnCode);
			success = false;
			break;
		}
	}
	else
	{
		ReturnCode = -1;
		// Most chances are the path to the .exe or the project were not set properly in GEditorIni file.
		UE_LOG(LogAkSoundData, Error, TEXT("Failed to run WwiseConsole: %s %s"), *wwiseConsoleCommand, *wwiseConsoleArguments);
	}

	return success;
}

void WwiseConsoleAkSoundDataBuilder::prepareRebuild(const FString& BankName, const FString& GeneratedSoundBanksPath)
{
	auto fileName = FString::Printf(TEXT("%s.json"), *BankName);

	for (auto& platform : initParameters.Platforms)
	{
		auto basePath = FPaths::Combine(GeneratedSoundBanksPath, platform);
		FPaths::NormalizeDirectoryName(basePath);

		auto pathToDelete = FPaths::Combine(basePath, fileName);
		FPaths::NormalizeDirectoryName(pathToDelete);
		platformFile->DeleteFile(*pathToDelete);

		auto& languagesArray = initParameters.Languages.Num() > 0 ? initParameters.Languages : WwiseProjectInfo.GetSupportedLanguages();

		for (auto& language : languagesArray)
		{
			pathToDelete = FPaths::Combine(basePath, language.Name, fileName);
			FPaths::NormalizeDirectoryName(pathToDelete);
			platformFile->DeleteFile(*pathToDelete);
		}
	}
}

TSharedPtr<FJsonObject> WwiseConsoleAkSoundDataBuilder::readJsonFile(const FString& JsonFileName)
{
	TSharedPtr<FJsonObject> jsonObject;

	FString jsonFileContent;
	if (!FFileHelper::LoadFileToString(jsonFileContent, *JsonFileName))
	{
		UE_LOG(LogAkSoundData, Warning, TEXT("Unable to parse JSON file: %s"), *JsonFileName);
		return jsonObject;
	}

	auto jsonReader = TJsonReaderFactory<>::Create(jsonFileContent);
	if (!FJsonSerializer::Deserialize(jsonReader, jsonObject) || !jsonObject.IsValid())
	{
		UE_LOG(LogAkSoundData, Warning, TEXT("Unable to parse JSON file: %s"), *JsonFileName);
		return jsonObject;
	}

	return jsonObject;
}

bool WwiseConsoleAkSoundDataBuilder::readBankData(UAkAssetData* AssetData, const FString& BankFile, IPlatformFile& FileManager, FCriticalSection* DataLock)
{
	TUniquePtr<IFileHandle> bankFileReader(FileManager.OpenRead(*BankFile, true));
	if (!bankFileReader)
	{
		return false;
	}

	auto fileSize = bankFileReader->Size();
	if (fileSize == 0)
	{
		return false;
	}


	TArray<uint8> newBankData;
	newBankData.SetNumUninitialized(fileSize);
	bankFileReader->Read(newBankData.GetData(), fileSize);

	return fillBankDataInAsset(AssetData, newBankData, DataLock);
}

template<typename MainAsset, typename PlatformAsset>
bool WwiseConsoleAkSoundDataBuilder::ReadBankDefinitionFile(MainAsset* mainAsset, PlatformAsset* platformAsset, const FString& platform, const FString& language, const FString& jsonFile)
{
	TSharedPtr<FJsonObject> jsonObject = readJsonFile(jsonFile);

	if (!jsonObject.IsValid())
	{
		return false;
	}

	TArray<TSharedPtr<FJsonValue>> soundBankArray = jsonObject->GetObjectField("SoundBanksInfo")->GetArrayField("SoundBanks");
	TSharedPtr<FJsonObject> soundBankData = soundBankArray[0]->AsObject();

	return ParseSoundBankInfo(mainAsset, platformAsset, platform, language, soundBankData);
}

bool WwiseConsoleAkSoundDataBuilder::readPluginInfo(UAkInitBank* InitBank, const FString& Platform, const FString& PluginInfoFileName)
{
	TSharedPtr<FJsonObject> jsonObject = readJsonFile(PluginInfoFileName);

	if (!jsonObject.IsValid())
	{
		return false;
	}

	auto& pluginInfoJsonObject = jsonObject->GetObjectField("PluginInfo");

	return parsePluginInfo(InitBank, Platform, pluginInfoJsonObject);
}


void WwiseConsoleAkSoundDataBuilder::ProcessFile(const FString& FullPath, const FString& GeneratedSoundBanksFolder)
{
	FString RelativePath = FullPath;
	FPaths::NormalizeDirectoryName(RelativePath);
	RelativePath.RemoveFromStart(GeneratedSoundBanksFolder);

	FString Directory;
	FString FileName;
	FString Extension;

	FPaths::Split(RelativePath, Directory, FileName, Extension);

	bool bIsBank = (Extension == TEXT("bnk"));
	bool bIsDefinitionFile = (Extension == TEXT("json"));
	if (!bIsBank && !bIsDefinitionFile)
	{
		return;
	}

	bool bIsUsingNewAssetManagement = AkUnrealHelper::IsUsingEventBased();

	if (!bIsUsingNewAssetManagement && bIsBank)
	{
		return;
	}

	TArray<FString> Parts;
	Directory.ParseIntoArray(Parts, TEXT("/"), true);

	FString Language;
	if (bIsUsingNewAssetManagement && Parts.Num() == 2)
	{
		Language = Parts[1];

		FScopeLock AutoLock(&AkAssetDatabase::Get().InitBankLock);
		AkAssetDatabase::Get().InitBank->AvailableAudioCultures.AddUnique(Language);
	}
	else
	{
		Language = TEXT("SFX");
	}

	FString Platform = Parts[0];

	auto sharedThis = SharedThis(this);

	FAssetData const* AkAudioEventIt = nullptr;
	FAssetData const* AkAuxBusIt = nullptr;
	FAssetData const* AkAudioBankIt = nullptr;

	FAssetData FoundAkAudioBank;

	if (bIsUsingNewAssetManagement)
	{
		auto BankGuid = AkUnrealHelper::BankNameToGuid(FileName);

		AkAudioEventIt = AkAssetDatabase::Get().EventMap.Find(BankGuid);
		AkAuxBusIt = AkAssetDatabase::Get().AuxBusMap.Find(BankGuid);
		AkAudioBankIt = AkAssetDatabase::Get().BankMap.Find(BankGuid);
	}
	else
	{
		auto FoundAssets = AkAssetDatabase::Get().BankMap.FindByName(FileName);
		if (FoundAssets.Num() > 0)
		{
			FoundAkAudioBank = FoundAssets[0];
			AkAudioBankIt = &FoundAkAudioBank;
		}
	}

	if (AkAudioEventIt)
	{
		struct EventRequiredData
		{
			UAkAudioEvent* AkAudioEvent = nullptr;
			UAkAssetData* EventPlatformData = nullptr;
		};

		TSharedPtr<EventRequiredData> RequiredData = MakeShared<EventRequiredData>();
		RequiredData->AkAudioEvent = Cast<UAkAudioEvent>(AkAudioEventIt->GetAsset());
		if (RequiredData->AkAudioEvent)
		{
			RequiredData->EventPlatformData = RequiredData->AkAudioEvent->FindOrAddAssetData(Platform, Language);
		}

		if (bIsBank)
		{
			if (RequiredData->AkAudioEvent && RequiredData->EventPlatformData)
			{
				if (sharedThis->readBankData(RequiredData->EventPlatformData, FullPath, *sharedThis->platformFile, &(RequiredData->AkAudioEvent->BulkDataWriteLock)))
				{
					sharedThis->MarkAssetDirty(RequiredData->AkAudioEvent);
					sharedThis->MarkAssetDirty(RequiredData->EventPlatformData);
				}
			}
		}
		else
		{
			if (RequiredData->AkAudioEvent && RequiredData->EventPlatformData)
			{
				if (sharedThis->ReadBankDefinitionFile(RequiredData->AkAudioEvent, RequiredData->EventPlatformData, Platform, Language, FullPath))
				{
					sharedThis->MarkAssetDirty(RequiredData->AkAudioEvent);
					sharedThis->MarkAssetDirty(RequiredData->EventPlatformData);
				}
			}
		}
	}
	else if (AkAuxBusIt)
	{
		auto AkAuxBus = Cast<UAkAuxBus>(AkAuxBusIt->GetAsset());

		if (AkAuxBus)
		{
			UAkAssetData* AuxBusPlatformData = AkAuxBus->FindOrAddAssetData(Platform, Language);

			if (AuxBusPlatformData)
			{
				if (bIsBank)
				{
					if (sharedThis->readBankData(AuxBusPlatformData, FullPath, *sharedThis->platformFile, &(AkAuxBus->BulkDataWriteLock)))
					{
						sharedThis->MarkAssetDirty(AkAuxBus);
					}
				}
				else
				{
					if (sharedThis->ReadBankDefinitionFile(AkAuxBus, AuxBusPlatformData, Platform, Language, FullPath))
					{
						sharedThis->MarkAssetDirty(AkAuxBus);
					}
				}
			}
		}
	}
	else if (AkAudioBankIt)
	{
		struct AudioBankRequiredData
		{
			UAkAudioBank* AkAudioBank = nullptr;
			UAkAssetData* AudioBankPlatformData = nullptr;
		};

		TSharedPtr<AudioBankRequiredData> RequiredData = MakeShared<AudioBankRequiredData>();
		RequiredData->AkAudioBank = Cast<UAkAudioBank>(AkAudioBankIt->GetAsset());
		if (RequiredData->AkAudioBank)
		{
			RequiredData->AudioBankPlatformData = RequiredData->AkAudioBank->FindOrAddAssetData(Platform, Language);
		}
		if (bIsBank)
		{
			if (RequiredData->AkAudioBank && RequiredData->AudioBankPlatformData)
			{
				if (sharedThis->readBankData(RequiredData->AudioBankPlatformData, FullPath, *sharedThis->platformFile, &(RequiredData->AkAudioBank->BulkDataWriteLock)))
				{
					sharedThis->MarkAssetDirty(RequiredData->AkAudioBank);
					sharedThis->MarkAssetDirty(RequiredData->AudioBankPlatformData);
				}
			}
		}
		else
		{
			if (RequiredData->AkAudioBank && RequiredData->AudioBankPlatformData)
			{
				if (sharedThis->ReadBankDefinitionFile(RequiredData->AkAudioBank, RequiredData->AudioBankPlatformData, Platform, Language, FullPath))
				{
					sharedThis->MarkAssetDirty(RequiredData->AkAudioBank);
					sharedThis->MarkAssetDirty(RequiredData->AudioBankPlatformData);
				}
			}
		}
	}
	else if (FileName == AkInitBankName || FileName == AkPluginInfoFileName)
	{
		auto InitBank = AkAssetDatabase::Get().InitBank;

		UAkAssetData* InitBankPlatformData = nullptr;
		InitBankPlatformData = InitBank->FindOrAddAssetData(Platform, Language);

		if (bIsBank)
		{
			if (sharedThis->readBankData(InitBankPlatformData, FullPath, *sharedThis->platformFile, &(InitBank->BulkDataWriteLock)))
			{
				sharedThis->MarkAssetDirty(InitBank);
			}
		}
		else if (FileName == AkPluginInfoFileName)
		{
			if (sharedThis->readPluginInfo(InitBank, Platform, FullPath))
			{
				sharedThis->MarkAssetDirty(InitBank);
			}
		}
		else
		{
			if (sharedThis->ReadBankDefinitionFile(InitBank, InitBankPlatformData, Platform, Language, FullPath))
			{
				sharedThis->MarkAssetDirty(InitBank);
			}			
		}
	}
}

