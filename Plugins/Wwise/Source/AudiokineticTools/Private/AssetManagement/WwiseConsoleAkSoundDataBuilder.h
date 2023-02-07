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

#include "AkSoundDataBuilder.h"

class FDirectoryWatcherModule;

class WwiseConsoleAkSoundDataBuilder : public AkSoundDataBuilder
{
public:
	WwiseConsoleAkSoundDataBuilder(const InitParameters& InitParameter);
	~WwiseConsoleAkSoundDataBuilder();

	void Init() override;
	void DoWork() override;

	void SetOverrideWwiseConsolePath(const FString& value) { overrideWwiseConsolePath = value; }

private:
	void OnDirectoryWatcher(const TArray<struct FFileChangeData>& ChangedFiles);

	bool runWwiseConsole();
	void ProcessFile(const FString& fullPath, const FString& generatedSoundBanksFolder);

	bool readBankData(UAkAssetData* AssetData, const FString& BankFile, IPlatformFile& FileManager, FCriticalSection* DataLock);

	TSharedPtr<FJsonObject> readJsonFile(const FString& JsonFileName);

	template<typename MainAsset, typename PlatformAsset>
	bool ReadBankDefinitionFile(MainAsset* mainAsset, PlatformAsset* platformAsset, const FString& platform, const FString& language, const FString& jsonFile);

	bool readPluginInfo(UAkInitBank* InitBank, const FString& Platform, const FString& PluginInfoFileName);

	void prepareRebuild(const FString& BankName, const FString& GeneratedSoundBanksPath);

private:
	FString watchDirectory;
	FDelegateHandle directoryWatcherDelegateHandle;
	FDirectoryWatcherModule* directoryWatcherModule = nullptr;

	FGraphEventArray AllWatcherTasks;
	TSet<FString> ProcessedPaths;

	FString overrideWwiseConsolePath;
};
