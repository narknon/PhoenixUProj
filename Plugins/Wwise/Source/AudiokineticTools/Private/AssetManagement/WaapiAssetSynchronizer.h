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

#include "AkWaapiClient.h"
#include "WwiseItemType.h"
#include "AssetData.h"

class WaapiAssetSynchronizer
{
public:
	void Init();
	void Uninit();

	static bool PauseAssetRegistryDelegates;

private:
	struct RenameData {
		const bool IsFolder;
		const int NewPathDepth;
		const int OldPathDepth;
		const FGuid Id;
		const FAssetData AssetData;
		const FString OldPath;
		const FString NewPath;
	};

private:
	void subscribeWaapiCallbacks();
	void unsubscribeWaapiCallbacks();

	void onAssetRemoved(const FAssetData& RemovedAssetData);
	void onAssetRenamed(const FAssetData& NewAssetData, const FString& OldPath);
	void renameAssets(TArray<RenameData>& assetsToRename);
	bool renameAsset(const RenameData& RenameData);
	void undoAssetRenames(const TArray<RenameData>& assetsToRename);
	void undoAssetRename(const FAssetData& NewAssetData, const FString& OldPath);

	void onRenamed(uint64_t Id, TSharedPtr<FJsonObject> Response);
	void onPreDeleted(uint64_t Id, TSharedPtr<FJsonObject> Response);
	void onChildAdded(uint64_t Id, TSharedPtr<FJsonObject> Response);
	void onChildRemoved(uint64_t Id, TSharedPtr<FJsonObject> Response);

	void assetUpdateTimerTick(float DeltaSeconds);

	static UClass* GetClassByName(const FString& stringAssetType);
	static  EWwiseItemType::Type GetTypeByName(const FString& stringAssetType);

private:
	FDelegateHandle projectLoadedHandle;
	FDelegateHandle connectionLostHandle;
	FDelegateHandle clientBeginDestroyHandle;

	FDelegateHandle assetAddedHandle;
	FDelegateHandle assetRemovedHandle;
	FDelegateHandle assetRenamedHandle;

	uint64 idRenamed = 0;
	uint64 idPreDeleted = 0;
	uint64 idChildAdded = 0;
	uint64 idChildRemoved = 0;

	TSet<FGuid> ignoreRenames;

	FDelegateHandle postEditorTickHandle;
	TSet<FGuid> assetsToDelete;
	TArray<RenameData> assetsToRename;

	float deleteTimer = 0.f;
	float syncTimer = 0.f;
	const FString UnnamedStateGroupFolder = TEXT("<Unnamed State Group>");

};
