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

#include "AssetManagement/SanitizeWwiseObjectPathCommandlet.h"

#if WITH_EDITOR
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "AssetTools/Public/AssetToolsModule.h"
#include "AkMediaAsset.h"
#include "AkAudioType.h"
#include "AkAssetBase.h"
#include "AkUnrealHelper.h"
#include "UnrealEd/Public/ObjectTools.h"

#define LOCTEXT_NAMESPACE "AkAudio"
#endif

USanitizeWwiseObjectPathCommandlet::USanitizeWwiseObjectPathCommandlet()
{
	IsClient = false;
	IsEditor = true;
	IsServer = false;
	LogToConsole = true;
}

int32 USanitizeWwiseObjectPathCommandlet::Main(const FString& Params)
{
	int32 ReturnCode = 0;
#if WITH_EDITOR
	FSlateApplication::Create();

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");

	AssetRegistryModule.Get().ScanPathsSynchronous({ AkUnrealHelper::GetBaseAssetPackagePath() });
	TArray<FAssetRenameData> assetsToRename;

	TArray<FAssetData> allAssets;
	AssetRegistryModule.Get().GetAssetsByClass(UAkMediaAsset::StaticClass()->GetFName(), allAssets, true);
	AssetRegistryModule.Get().GetAssetsByClass(UAkAssetPlatformData::StaticClass()->GetFName(), allAssets, true);
	AssetRegistryModule.Get().GetAssetsByClass(UAkAudioType::StaticClass()->GetFName(), allAssets, true);

	for (auto& assetData : allAssets)
	{
		auto oldPackagePath = assetData.ObjectPath.ToString();
		auto sanitizedPackagePath = ObjectTools::SanitizeObjectPath(oldPackagePath);

		if (oldPackagePath != sanitizedPackagePath)
		{
			assetData.GetAsset();
			assetsToRename.Emplace(FSoftObjectPath(oldPackagePath), FSoftObjectPath(sanitizedPackagePath));
		}
	}

	if (assetsToRename.Num() > 0)
	{
		if (!AssetToolsModule.Get().RenameAssets(assetsToRename))
		{
			ReturnCode = 1;
		}
	}
#endif

	return ReturnCode;
}

#undef LOCTEXT_NAMESPACE
