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

#include "DirectoryWatcher/Public/IDirectoryWatcher.h"
#include "WaapiAssetSynchronizer.h"
#include "WwiseProject/WwiseWorkUnitParser.h"
#include "ContentBrowser/Public/ContentBrowserDelegates.h"

class AkAssetManagementManager
{
public:
	void Init();
	void Uninit();

	void DoAssetSynchronization();
	void DoAssetMigration();

	bool IsInited() const { return isInited; }

	static void ClearSoundBanksForMigration();
	static void ModifyProjectSettings();

private:
	void onWwiseDirectoryChanged(const TArray<FFileChangeData>& ChangedFiles);
	bool onAssetViewDrop(const FAssetViewDragAndDropExtender::FPayload& Payload);
	bool onAssetViewDragOver(const FAssetViewDragAndDropExtender::FPayload& Payload);
	bool onAssetViewDragLeave(const FAssetViewDragAndDropExtender::FPayload& Payload);

private:
	bool isInited = false;

	WaapiAssetSynchronizer waapiAssetSync;
	WwiseWorkUnitParser workUnitParser;

	FString wwiseProjectFolder;
	FDelegateHandle wwiseDirectoryChangedHandle;

	TUniquePtr<FAssetViewDragAndDropExtender> dragDropExtender;
	bool canDrop = false;
	bool onlyParsePhysicalFolders =false;
};