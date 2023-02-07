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

#include "AkAssetDatabase.h"
#include "AkAcousticTexture.h"
#include "AkAudioBank.h"
#include "AkFolder.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkGroupValue.h"
#include "AkInitBank.h"
#include "AkMediaAsset.h"
#include "AkRtpc.h"
#include "AkSettings.h"
#include "AkStateValue.h"
#include "AkSwitchValue.h"
#include "AkTrigger.h"
#include "AkUnrealHelper.h"
#include "AkWaapiClient.h"
#include "AkAudioDevice.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "AssetTools/Public/AssetToolsModule.h"
#include "Async/Async.h"
#include "ContentBrowser/Public/ContentBrowserModule.h"
#include "ContentBrowser/Public/IContentBrowserSingleton.h"
#include "HAL/FileManager.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "Misc/FeedbackContext.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "Misc/RedirectCollector.h"
#include "Misc/ScopedSlowTask.h"
#include "ToolBehavior/AkToolBehavior.h"
#include "AssetManagement/WaapiAssetSynchronizer.h"
#include "UnrealEd/Public/ObjectTools.h"
#include "UnrealEd/Public/PackageTools.h"
#include "Logging/LogMacros.h"

#define LOCTEXT_NAMESPACE "AkAudio"

DEFINE_LOG_CATEGORY_STATIC(LogAkAssetDatabase, Log, All);

const FString AkAssetDatabase::TemporaryGroupValueFolder= TEXT("TEMPORARY_GROUP_VALUE_FOLDER");

AkAssetDatabase& AkAssetDatabase::Get()
{
	static AkAssetDatabase instance;
	return instance;
}

AkAssetDatabase::AkAssetDatabase()
{
	AssetRegistryModule = &FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	auto& AssetRegistry = AssetRegistryModule->Get();
	AssetRegistry.OnAssetAdded().AddRaw(this, &AkAssetDatabase::OnAssetAdded);
	AssetRegistry.OnAssetRemoved().AddRaw(this, &AkAssetDatabase::onAssetRemoved);
	AssetRegistry.OnAssetRenamed().AddRaw(this, &AkAssetDatabase::onAssetRenamed);
	AssetRegistry.OnAssetUpdated().AddRaw(this, &AkAssetDatabase::onAssetUpdated);

	AssetToolsModule = &FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
}

void AkAssetDatabase::Init()
{
	FindInitBank();
	CreateInitBankIfNeeded();

	OnTick = FTickerDelegate::CreateRaw(this, &AkAssetDatabase::Tick);
	TickDelegateHandle = FCoreTickerType::GetCoreTicker().AddTicker(OnTick);
	UAkInitBank::OnInitBankChanged.BindLambda([this](UAkInitBank* NewInitBank) { InitBank = NewInitBank; });
}

void AkAssetDatabase::ScanForAkAssets()
{
	if (AudioTypeMap.TypeMap.Num() > 0)
	{
		Clear();
	}
	TArray<FAssetData> AllAssets;
	AssetRegistryModule->Get().GetAssetsByClass(UAkAudioType::StaticClass()->GetFName(), AllAssets, true);

	FScopedSlowTask SlowTask(static_cast<float>(AllAssets.Num()), LOCTEXT("AK_ScanAssets", "Scanning sound data assets..."));
	SlowTask.MakeDialog();

	for (auto& AssetData : AllAssets)
	{
		FString Message = FString::Printf(TEXT("Scanning sound data asset: %s"), *AssetData.AssetName.ToString());
		SlowTask.EnterProgressFrame(1.0f, FText::FromString(Message));

		if (AssetData.GetClass()->IsChildOf<UAkAudioType>())
		{
			auto AssetID = AssetData.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));
			Add(AssetID, AssetData);
		}
	}
}

 void AkAssetDatabase::FindInitBank()
 {
	 TArray<FAssetData> InitBankAssets;
	 AssetRegistryModule->Get().GetAssetsByClass(UAkInitBank::StaticClass()->GetFName(), InitBankAssets);

	 if (InitBankAssets.Num() > 0)
	 {
		 auto AssetID = InitBankAssets[0].GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));
		 Add(AssetID, InitBankAssets[0]);
	 }
 }

void AkAssetDatabase::Clear()
{
	{
		FScopeLock autoLock(&InitBankLock);
		InitBank = nullptr;
	}

	AcousticTextureMap.Empty();
	EventMap.Empty();
	AuxBusMap.Empty();
	GroupValueMap.Empty();
	TriggerMap.Empty();
	RtpcMap.Empty();
	BankMap.Empty();
	FolderMap.Empty();
	AudioTypeMap.Empty();
}

bool AkAssetDatabase::IsInWwiseFolderHeirarchy(const FString& AssetPath)
{
	auto folderAsset = GetContainingFolder(AssetPath);
	if (folderAsset != nullptr)
	{
		if (folderAsset->assetType == EWwiseItemType::PhysicalFolder) {
			return true;
		}
		else
		{
			return IsInWwiseFolderHeirarchy(FPaths::GetPath(AssetPath));
		}
	}
	return false;
}


UAkFolder* AkAssetDatabase::GetContainingFolder(const FString& AssetPath)
{
	FString folderPath;
	FString FileName;
	FString Extension;
	FPaths::Split(AssetPath, folderPath, FileName, Extension);
	auto folderName = FPaths::GetBaseFilename(folderPath) + TEXT("_FOLDER");

	auto folderAssetPath = FString::Format(TEXT("{0}/{1}.{1}"), { folderPath, folderName, folderName });
	auto folderAsset = AssetRegistryModule->Get().GetAssetByObjectPath(FName(folderAssetPath));
	if (folderAsset.IsValid())
	{
		if (auto folderInfo = Cast<UAkFolder>(folderAsset.GetAsset()))
		{
			return folderInfo;
		}
	}
	return nullptr;
}

FString AkAssetDatabase::GetWwisePathFromAssetPath(const FString& AssetPath)
{
	const auto AkSettings = GetDefault<UAkSettings>();
	if (!AkSettings)
	{
		// todo slaptiste: should we consider using an alternate path if AkSettings is not found???
		return {};
	}

	auto folderAsset = GetContainingFolder(AssetPath);
	if (folderAsset != nullptr)
	{
		return FString::Format(TEXT("{0}/{1}"), { folderAsset->WwiseFolderPath, FPaths::GetBaseFilename(AssetPath) });
	}
	return {};
}

FGuid AkAssetDatabase::GetFolderGuid(const FString& AssetPath)
{
	auto folderAsset = GetContainingFolder(AssetPath);
	if (folderAsset != nullptr)
	{
		return folderAsset->ID;
	}
	return {};
}

FString AkAssetDatabase::UpdateWwiseFolderPaths(const FString& AssetPath)
{
	auto folderAsset = GetContainingFolder(AssetPath);
	auto currentFolderAssetLocation = FPaths::GetPath(AssetPath);
	if (folderAsset != nullptr)
	{
		if (folderAsset->UnrealFolderPath != currentFolderAssetLocation)
		{
			auto parentWwisePath = UpdateWwiseFolderPaths(currentFolderAssetLocation);
			folderAsset->UnrealFolderPath = currentFolderAssetLocation;

			auto folderName = FPaths::GetBaseFilename(currentFolderAssetLocation);
			folderAsset->WwiseFolderPath = FString::Format(TEXT("{0}/{1}"),
				{ parentWwisePath,  folderName });
		}
		return folderAsset->WwiseFolderPath;
	}
	return {};
}

FString AkAssetDatabase::GetBaseFolderForAssetType(const UClass* Klass)
{
	if (Klass->IsChildOf<UAkAcousticTexture>())
	{
		return AkAssetTraits<UAkAcousticTexture>::BaseFolder();
	}
	else if (Klass->IsChildOf<UAkAudioEvent>())
	{
		return AkAssetTraits<UAkAudioEvent>::BaseFolder();
	}
	else if (Klass->IsChildOf<UAkAuxBus>())
	{
		return AkAssetTraits<UAkAuxBus>::BaseFolder();
	}
	else if (Klass->IsChildOf<UAkRtpc>())
	{
		return AkAssetTraits<UAkRtpc>::BaseFolder();
	}
	else if (Klass->IsChildOf<UAkStateValue>())
	{
		return AkAssetTraits<UAkStateValue>::BaseFolder();
	}
	else if (Klass->IsChildOf<UAkSwitchValue>())
	{
		return AkAssetTraits<UAkSwitchValue>::BaseFolder();
	}
	else if (Klass->IsChildOf<UAkTrigger>())
	{
		return AkAssetTraits<UAkTrigger>::BaseFolder();
	}

	return AkAssetTraits<UAkAudioType>::BaseFolder();
}

bool AkAssetDatabase::Add(const FGuid& Id, const FAssetData& AssetData)
{
	FGuid finalId = Id;

	if (!AkToolBehavior::Get()->AkAssetDatabase_ValidateAssetId(finalId))
	{
		return false;
	}

	UClass* assetKlass = AssetData.GetClass();

	if (assetKlass->IsChildOf<UAkAcousticTexture>())
	{
		AcousticTextureMap.Add(finalId, AssetData);
		if (UAkSettings* AkSettings = GetMutableDefault<UAkSettings>())
		{
			if (FAkAcousticTextureParams* params = AkSettings->AcousticTextureParamsMap.Find(finalId))
			{
				auto shortID = AssetData.GetTagValueRef<uint32>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ShortID));
				params->shortID = shortID;
			}
		}
	}

	else if (assetKlass->IsChildOf<UAkAudioEvent>())
	{
		EventMap.Add(finalId, AssetData);
	}
	else if (assetKlass->IsChildOf<UAkAuxBus>())
	{
		AuxBusMap.Add(finalId, AssetData);
	}
	else if (assetKlass->IsChildOf<UAkGroupValue>())
	{
		GroupValueMap.Add(finalId, AssetData);
	}
	else if (assetKlass->IsChildOf<UAkTrigger>())
	{
		TriggerMap.Add(finalId, AssetData);
	}
	else if (assetKlass->IsChildOf<UAkRtpc>())
	{
		RtpcMap.Add(finalId, AssetData);
	}
	else if (assetKlass->IsChildOf<UAkAudioBank>())
	{
		BankMap.Add(finalId, AssetData);
	}
	else if (assetKlass->IsChildOf<UAkFolder>())
	{
		FolderMap.Add(finalId, AssetData);
	}
	else if (assetKlass->IsChildOf<UAkInitBank>())
	{
		InitBank = Cast<UAkInitBank>(AssetData.GetAsset());
	}
	else
	{
		return false;
	}

	AudioTypeMap.Add(finalId, AssetData);
	return true;
}

bool AkAssetDatabase::Remove(const FAssetData& AssetData)
{
	auto AssetKlass = AssetData.GetClass();

	if (AssetKlass->IsChildOf<UAkFolder>() || AssetKlass->IsChildOf<UAkAuxBus>())
	{
		removeFolder(AssetData.PackagePath.ToString());
	}

	auto bSuccessfullyRemoved = false;
	auto AssetID = AssetData.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));
	if (ignoreDeletes.Contains(AssetID))
	{
		ignoreDeletes.Remove(AssetID);
	}
	else
	{
		if (AssetKlass->IsChildOf<UAkAudioEvent>())
		{
			if (auto AkAudioEvent = Cast<UAkAudioEvent>(AssetData.GetAsset()))
			{
				AkAudioEvent->ClearRequiredBank();
			}
		}
		bSuccessfullyRemoved = AkToolBehavior::Get()->AkAssetDatabase_Remove(this, AssetData);
	}

	return bSuccessfullyRemoved;
}

void AkAssetDatabase::CreateInitBankIfNeeded()
{
	FScopeLock autoLock(&InitBankLock);

	if (!InitBank)
	{
		const FString InitBankPath = AkToolBehavior::Get()->AkAssetDatabase_GetInitBankPackagePath();
		auto newInitBank = AssetToolsModule->Get().CreateAsset(TEXT("InitBank"), InitBankPath, UAkInitBank::StaticClass(), nullptr);
		InitBank = Cast<UAkInitBank>(newInitBank);
		if (InitBank)
		{
			InitBank->ID = AkUnrealHelper::InitBankID;
		}
	}
}

void AkAssetDatabase::removeFolder(const FGuid& FolderAssetGuid)
{
	auto assetPtr = AudioTypeMap.Find(FolderAssetGuid);
	if (!assetPtr)
	{
		return;
	}
	auto assetInstance = *assetPtr;
	if (auto folder = Cast<UAkFolder>(assetInstance.GetAsset()))
	{
		removeFolder(folder->UnrealFolderPath);
	}
}

void AkAssetDatabase::removeFolder(const FString& UnrealFolderPath)
{
	FoldersPendingRemoval.Add(UnrealFolderPath);
}

void AkAssetDatabase::removeFolders(const TSet<FString>& folders)
{
	for (auto folder : folders)
	{
		FoldersPendingRemoval.Add(folder);
	}
}


void AkAssetDatabase::checkFoldersToRemove()
{
	if (FoldersPendingRemoval.Num() == 0) return;

	auto& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	auto copyFolders = TSet<FString>();
	copyFolders.Append(FoldersPendingRemoval);
	for (auto& assetPath : copyFolders)
	{
		bool hasAssets = AssetRegistryModule->Get().HasAssets(*assetPath, true);

		auto directoryPath = FPackageName::LongPackageNameToFilename(assetPath);

		if (!hasAssets)
		{
			if (platformFile.DeleteDirectoryRecursively(*directoryPath))
			{
				AssetRegistryModule->Get().RemovePath(assetPath);
			}
			FoldersPendingRemoval.Remove(assetPath);
		}
	}
}

bool AkAssetDatabase::IsFolderType(const   EWwiseItemType::Type ItemType)
{
	return ItemType == EWwiseItemType::Folder || ItemType == EWwiseItemType::PhysicalFolder ||
		ItemType == EWwiseItemType::Bus ||
		ItemType == EWwiseItemType::StateGroup || ItemType == EWwiseItemType::SwitchGroup ||
		ItemType == EWwiseItemType::NestedWorkUnit || ItemType == EWwiseItemType::StandaloneWorkUnit;
}

UPackage* AkAssetDatabase::CreateOrRenameAsset(const UClass* Klass, const FGuid& Id, const FString& Name, const FString& AssetName, const FString& RelativePath, const FGuid& GroupId, const AssetSyncMode& syncMode, bool& FoundAsset, bool& AssetModified)
{
	check(IsInGameThread());

	FoundAsset = false;
	AssetModified = false;
	auto* AudioDevice = FAkAudioDevice::Get();

	auto parentPath = RelativePath;

	// If we are creating an AuxBus, it should be in a identically-named folder 
	if (!Klass->IsChildOf<UAkAuxBus>())
	{
		parentPath.RemoveFromEnd(Name);
	}

	auto AssetPackagePath = ObjectTools::SanitizeObjectPath(FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), parentPath));
	auto AssetPath = FPaths::Combine(AssetPackagePath, AssetName + TEXT(".") + AssetName);

	auto assetDataPtr = AudioTypeMap.Find(Id);
	if (!assetDataPtr)
	{
		FString ValueName = AssetName;
		auto assetInstance = Cast<UAkAudioType>(AssetToolsModule->Get().CreateAsset(AssetName, AssetPackagePath, const_cast<UClass*>(Klass), nullptr));
		if (!assetInstance)
		{
			return nullptr;
		}

		assetInstance->ID = Id;
		if (auto groupValue = Cast<UAkGroupValue>(assetInstance))
		{
			FString GroupName;
			AssetName.Split(TEXT("-"), &GroupName, &ValueName);
			groupValue->GroupID = GroupId;
			groupValue->GroupShortID = FAkAudioDevice::GetIDFromString(GroupName);
		}

		assetInstance->ShortID = FAkAudioDevice::GetIDFromString(ValueName);

		Add(Id, assetInstance);
		PendingAssetCreates.Remove(Id);
		FoundAsset = true;
		AssetModified = true;
		return assetInstance->GetOutermost();
	}

	auto objectPath = assetDataPtr->ObjectPath;

	// Asset has been renamed/moved
	if (objectPath != *AssetPath)
	{
		AssetModified = true;
		TArray<FAssetRenameData> assetsToRename = { { FSoftObjectPath(objectPath), FSoftObjectPath(AssetPath) } };

		auto baseFolderPath = FPaths::GetBaseFilename(assetDataPtr->PackagePath.ToString());
		auto isAuxBusAssetFolder = assetDataPtr->AssetName.ToString() == baseFolderPath;

		// If we are renaming/moving an Aux Bus, all nested busses should be moved as well
		if (syncMode == AssetSyncMode::WAAPI 
			&& Klass->IsChildOf<UAkAuxBus>()
			&& isAuxBusAssetFolder 
			&& * AssetPackagePath != assetDataPtr->PackagePath )
		{
			if (GWarn && GWarn->GetScopeStack().Num() > 0)
			{
				moveFolder(assetDataPtr->ObjectPath.ToString(), assetDataPtr->PackagePath.ToString(), AssetPackagePath, assetsToRename);
			}
			else
			{
				// WG-46823: Workaround for random crash in Unreal code
				AsyncTask(ENamedThreads::GameThread, [this, assetDataPtr, AssetPackagePath, assetsToRename] {
					moveFolder(assetDataPtr->ObjectPath.ToString(), assetDataPtr->PackagePath.ToString(), AssetPackagePath, assetsToRename);
					});
			}
		}

		else
		{
			if (auto akAudioEvent = Cast<UAkAudioEvent>(assetDataPtr->GetAsset()))
			{
				RenameLocalizedAssets(akAudioEvent, parentPath, AssetName, assetsToRename);
			}

			if (GWarn && GWarn->GetScopeStack().Num() > 0)
			{
				AssetToolsModule->Get().RenameAssets(assetsToRename);
			}
			else
			{
				// WG-46823: Workaround for random crash in Unreal code
				AsyncTask(ENamedThreads::GameThread, [this, assetsToRename] {
					AssetToolsModule->Get().RenameAssets(assetsToRename);
					});
			}
		}
	}

	FoundAsset = true;
	return nullptr;
}

UObject* AkAssetDatabase::CreateOrRenameFolder(const UClass* Klass, const FGuid& Id, const FString& Name, const FString& RelativePath, const EWwiseItemType::Type FolderType, const AssetSyncMode& syncMode, bool& AssetModified)
{
	check(IsInGameThread());

	auto* AudioDevice = FAkAudioDevice::Get();

	auto parentPath = RelativePath;
	auto AssetPackagePath = ObjectTools::SanitizeObjectPath(FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), parentPath));
	auto sanitizedName = ObjectTools::SanitizeObjectPath(Name) + TEXT("_FOLDER");
	auto AssetPath = FPaths::Combine(AssetPackagePath, sanitizedName + TEXT(".") + sanitizedName);
	AssetModified = false;
	auto assetInstancePtr = AudioTypeMap.Find(Id);
	if (!assetInstancePtr)
	{
		FString ValueName = Name;
		auto assetInstance = Cast<UAkFolder>(AssetToolsModule->Get().CreateAsset(sanitizedName, AssetPackagePath, const_cast<UClass*>(Klass), nullptr));
		if (!assetInstance)
		{
			return nullptr;
		}

		assetInstance->ID = Id;
		assetInstance->UnrealFolderPath = AssetPackagePath;
		assetInstance->WwiseFolderPath = RelativePath;
		assetInstance->assetType = FolderType;
		assetInstance->ShortID = FAkAudioDevice::GetIDFromString(ValueName);

		Add(Id, assetInstance);
		PendingAssetCreates.Remove(Id);
		AssetModified = true;
		return assetInstance;
	}


	auto assetInstance = Cast<UAkFolder>(assetInstancePtr->GetAsset());

	if (!assetInstance)
		return nullptr;

	if (assetInstance->UnrealFolderPath != AssetPackagePath) {
		assetInstance->UnrealFolderPath = AssetPackagePath;
	}

	if (assetInstance->WwiseFolderPath != RelativePath) {
		assetInstance->WwiseFolderPath = RelativePath;
	}

	if (assetInstance->assetType != FolderType) {
		assetInstance->assetType = FolderType;
	}

	auto objectPath = assetInstance->GetPathName();
	if (objectPath != AssetPath)
	{
		if (Name != assetInstance->GetName())
		{
			assetInstance->ShortID = FAkAudioDevice::GetIDFromString(Name);
		}

		AssetModified = true;
		TArray<FAssetRenameData> assetsToRename = { { FSoftObjectPath(objectPath), FSoftObjectPath(AssetPath) } };
		auto oldFolderPath = FPaths::GetPath(objectPath);
		if (syncMode == AssetSyncMode::WAAPI)
		{
			if (GWarn && GWarn->GetScopeStack().Num() > 0)
			{
				moveFolder(oldFolderPath, assetInstance, assetsToRename);
			}
			else
			{
				// WG-46823: Workaround for random crash in Unreal code
				AsyncTask(ENamedThreads::GameThread, [this, oldFolderPath, assetInstance, assetsToRename] {
					moveFolder(oldFolderPath, assetInstance, assetsToRename);
					});
			}
		}
		else
		{
			if (GWarn && GWarn->GetScopeStack().Num() > 0)
			{
				AssetToolsModule->Get().RenameAssets(assetsToRename);
			}
			else
			{
				// WG-46823: Workaround for random crash in Unreal code
				AsyncTask(ENamedThreads::GameThread, [this, assetsToRename] {
					AssetToolsModule->Get().RenameAssets(assetsToRename);
					});
			}
			removeFolder(oldFolderPath);
		}
	}
	return assetInstance;
}

void AkAssetDatabase::moveFolder(const FString& OldPath, const UAkFolder* newFolder, TArray<FAssetRenameData> assetsToRename)
{
	moveFolder(newFolder->GetPathName(), OldPath, newFolder->UnrealFolderPath, assetsToRename);
}

void AkAssetDatabase::moveFolder(const FString& ObjectPath, const FString& OldPath, const FString& newFolder, TArray<FAssetRenameData> assetsToRename)
{
	auto name = FName(OldPath);
	TArray < FAssetData > childAssets;
	auto success = AssetRegistryModule->Get().GetAssetsByPath(name, childAssets, true, false);
	for (auto& asset : childAssets)
	{
		auto assetName = asset.AssetName.ToString();
		auto packagePath = asset.ObjectPath.ToString();

		if (packagePath == ObjectPath) 
		{
			continue;
		}

		FString newPackagePath = packagePath.Replace(*OldPath, *newFolder);
		assetsToRename.Emplace(FSoftObjectPath(packagePath), FSoftObjectPath(newPackagePath));
		if (asset.GetClass()->IsChildOf<UAkAudioType>()) 
		{
			auto assetId = asset.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));
			ignoreDeletes.Add(assetId);
			if (asset.GetClass()->IsChildOf<UAkAudioEvent>())
			{
				RenameLocalizedAssets(Cast<UAkAudioEvent>(asset.GetAsset()), newFolder, assetName, assetsToRename);
			}
		}
	}

	if (assetsToRename.Num() > 0)
	{
		WaapiAssetSynchronizer::PauseAssetRegistryDelegates = true;
		AssetToolsModule->Get().RenameAssets(assetsToRename);
		FixUpRedirectors(newFolder);

		WaapiAssetSynchronizer::PauseAssetRegistryDelegates = false;
	}

	removeFolder(OldPath);
}

void AkAssetDatabase::RenameGroupValues(const FGuid& GroupId, const FString& GroupName, const FString& Path)
{
	TArray<FAssetData> findResults;
	{
		FScopeLock autoLock(&GroupValueMap.CriticalSection);
		for (auto& entry : GroupValueMap.TypeMap)
		{
			auto groupID = entry.Value.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkGroupValue, GroupID));
			if (groupID == GroupId)
			{
				findResults.Emplace(entry.Value);
			}
		}
	}

	if (findResults.Num() <= 0)
		return;

	auto AssetPackagePath = ObjectTools::SanitizeObjectPath(FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), Path));

	TArray<FAssetRenameData> assetsToRename;
	for (auto& assetData : findResults)
	{
		FString valueName;
		assetData.AssetName.ToString().Split(TEXT("-"), nullptr, &valueName);
		auto newAssetPath = FPaths::Combine(AssetPackagePath, FString::Printf(TEXT("%s-%s.%s-%s"), *GroupName, *valueName, *GroupName, *valueName));
		assetsToRename.Emplace(assetData.ToSoftObjectPath(), FSoftObjectPath(newAssetPath));

		auto oldAssetGroupPath = assetData.PackagePath.ToString();
		auto strippedPath = oldAssetGroupPath;
		strippedPath.RemoveFromStart(AkUnrealHelper::GetBaseAssetPackagePath() + TEXT("/"));
		if (strippedPath.StartsWith(TemporaryGroupValueFolder))
		{
			removeFolder(oldAssetGroupPath);
			removeFolder(FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), TemporaryGroupValueFolder));
		}
	}

	if (assetsToRename.Num() > 0)
	{
		AssetToolsModule->Get().RenameAssets(assetsToRename);
	}
}

void AkAssetDatabase::DeleteAsset(const FGuid& Id)
{
	check(IsInGameThread());

	auto foundAssetPtr = AudioTypeMap.Find(Id);

	if (!foundAssetPtr)
	{
		return;
	}

	if (foundAssetPtr->GetClass()->IsChildOf<UAkAudioType>())
	{
		Remove(*foundAssetPtr);

		TArray<FAssetData> assetsToDelete = { *foundAssetPtr };
		FillAssetsToDelete(foundAssetPtr, assetsToDelete);

		if (assetsToDelete.Num() > 0)
		{
			ObjectTools::DeleteAssets(assetsToDelete, true);
		}
	}
}

void AkAssetDatabase::DeleteAssets(const TSet<FGuid>& AssetsId)
{
	check(IsInGameThread());

	TArray<FAssetData> assetsToDelete;
	for (auto& id : AssetsId)
	{
		auto foundAssetPtr = AudioTypeMap.Find(id);

		if (!foundAssetPtr)
		{
			return;
		}

		assetsToDelete.Add(*foundAssetPtr);
		FillAssetsToDelete(foundAssetPtr, assetsToDelete);
		Remove(*foundAssetPtr);
	}

	if (assetsToDelete.Num() > 0)
	{
		int numAssetsDeleted = ObjectTools::DeleteAssets(assetsToDelete, true);
	}
}

void AkAssetDatabase::FillAssetsToDelete(FAssetData* AssetData, TArray<FAssetData>& AssetDataToDelete)
{
	if (AssetData->GetClass()->IsChildOf<UAkAudioEvent>())
	{
		auto AkAudioEvent = Cast<UAkAudioEvent>(AssetData->GetAsset());
		for (auto& Entry : AkAudioEvent->LocalizedPlatformAssetDataMap)
		{
			if (auto PlatformData = Entry.Value)
			{
				AssetDataToDelete.Emplace(PlatformData);
				TArray<TSoftObjectPtr<UAkMediaAsset>> mediaList;
				PlatformData->GetMediaList(mediaList);
				processMediaToDelete(PlatformData, mediaList, AssetDataToDelete);
			}
		}
	}

	if (AssetData->GetClass()->IsChildOf<UAkAssetBase>()) {
		auto AssetBase = Cast<UAkAssetBase>(AssetData->GetAsset());
		TArray<TSoftObjectPtr<UAkMediaAsset>> MediaList;
		AssetBase->GetMediaList(MediaList);
		processMediaToDelete(AssetBase, MediaList, AssetDataToDelete);
	}
}

void AkAssetDatabase::MoveAllAssets(const FString& OldBaseAssetPath, const FString& NewBaseAssetPath)
{
	TArray<FAssetRenameData> assetsToRename;

	TArray<FAssetData> allAssets;
	AssetRegistryModule->Get().GetAssetsByClass(UAkMediaAsset::StaticClass()->GetFName(), allAssets, true);
	AssetRegistryModule->Get().GetAssetsByClass(UAkAssetPlatformData::StaticClass()->GetFName(), allAssets, true);

	for (auto& entry : AudioTypeMap.TypeMap)
	{
		allAssets.Emplace(entry.Value);
	}

	for (auto& assetData : allAssets)
	{
		auto packagePath = assetData.ObjectPath.ToString();

		if (packagePath.StartsWith(OldBaseAssetPath))
		{
			auto index = assetsToRename.Emplace(FSoftObjectPath(packagePath), FSoftObjectPath(packagePath.Replace(*OldBaseAssetPath, *NewBaseAssetPath)));
			assetsToRename[index].Asset = assetData.GetAsset();
		}
	}

	if (assetsToRename.Num() > 0)
	{
		AssetToolsModule->Get().RenameAssets(assetsToRename);

		FixUpRedirectors(NewBaseAssetPath);
	}

	// Move the loose external source .wems
	TArray<FString> WemsToMove;
	auto OldWwiseAudioFolder = OldBaseAssetPath;
	auto NewWwiseAudioFolder = NewBaseAssetPath;
	OldWwiseAudioFolder.RemoveFromStart(TEXT("/Game/"));
	NewWwiseAudioFolder.RemoveFromStart(TEXT("/Game/"));
	auto OldAudioFolderFullPath = AkUnrealHelper::GetContentDirectory() / OldWwiseAudioFolder;
	IFileManager::Get().FindFilesRecursive(WemsToMove, *OldAudioFolderFullPath, TEXT("*.wem"), true, false);
	IFileManager::Get().FindFilesRecursive(WemsToMove, *OldAudioFolderFullPath, TEXT("Wwise.dat"), true, false, false);
	for (auto WemFile : WemsToMove)
	{
		auto NewPath = WemFile.Replace(*OldWwiseAudioFolder, *NewWwiseAudioFolder);
		IFileManager::Get().Move(*NewPath, *WemFile);
	}

	// Delete the old folder hierarchy
	IFileManager::Get().DeleteDirectory(*OldAudioFolderFullPath, false, true);
}



void AkAssetDatabase::FixUpRedirectors(const FString& AssetPackagePath)
{
	TArray<UObjectRedirector*> redirectorsToFix;

	TArray<FAssetData> foundRedirectorsData;
	AssetRegistryModule->Get().GetAssetsByClass(UObjectRedirector::StaticClass()->GetFName(), foundRedirectorsData);

	if (foundRedirectorsData.Num() > 0)
	{
		for (auto& entry : foundRedirectorsData)
		{
			if (auto redirector = Cast<UObjectRedirector>(entry.GetAsset()))
			{
				if (redirector->DestinationObject)
				{
					auto pathName = redirector->DestinationObject->GetPathName();
					if (pathName.StartsWith(AssetPackagePath))
					{
						redirectorsToFix.Add(redirector);
					}
				}
			}
		}
	}

	if (redirectorsToFix.Num() > 0)
	{
		AssetToolsModule->Get().FixupReferencers(redirectorsToFix);
	}
}

bool AkAssetDatabase::CanBeDropped(const FAssetData& AssetData, FName PackagePath, CanBeDroppedSource Source) const
{
	auto akAudioType = Cast<UAkAudioType>(AssetData.GetAsset());
	if (!akAudioType)
	{
		return false;
	}

	auto expectedPackagePath = FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), GetBaseFolderForAssetType(akAudioType->GetClass()));

	if (!PackagePath.ToString().StartsWith(expectedPackagePath, ESearchCase::IgnoreCase))
	{
		return false;
	}

	if (!AudioTypeMap.Find(akAudioType->ID))
	{
		return true;
	}

	if (PackagePath == AssetData.PackagePath)
	{
		return false;
	}

	auto assetName = AssetData.AssetName.ToString();

	auto isValidName = [&PackagePath, Source](const auto& map, const FString& assetName) {
		auto assetsFound = map.FindByName(assetName);

		if (assetsFound.Num() > 0)
		{
			if (Source == CanBeDroppedSource::FromContentBrowser)
			{
				for (FAssetData& assetData : assetsFound)
				{
					auto assetPackagePath = assetData.PackagePath.ToString();
					if (assetPackagePath != PackagePath.ToString())
					{
						return true;
					}
				}
			}

			return false;
		}
		else
		{
			return true;
		}
	};

	if (akAudioType->IsA<UAkAcousticTexture>())
	{
		return isValidName(AcousticTextureMap, assetName);
	}
	else if (akAudioType->IsA<UAkAudioEvent>())
	{
		return isValidName(EventMap, assetName);
	}
	else if (akAudioType->IsA<UAkAuxBus>())
	{
		return isValidName(AuxBusMap, assetName);
	}
	else if (akAudioType->IsA<UAkGroupValue>())
	{
		return isValidName(GroupValueMap, assetName);
	}
	else if (akAudioType->IsA<UAkTrigger>())
	{
		return isValidName(TriggerMap, assetName);
	}
	else if (akAudioType->IsA<UAkRtpc>())
	{
		return isValidName(RtpcMap, assetName);
	}

	return false;
}

void AkAssetDatabase::processMediaToDelete(UObject* Asset, const TArray<TSoftObjectPtr<UAkMediaAsset>>& MediaList, TArray<FAssetData>& AssetDataToDelete)
{
	auto assetPackageName = Asset->GetOutermost()->GetFName();

	for (auto& media : MediaList)
	{
		auto mediaPackageName = FName(*media.GetLongPackageName());

		TArray<FName> dependencies;
#if UE_4_26_OR_LATER
		AssetRegistryModule->Get().GetReferencers(mediaPackageName, dependencies, UE::AssetRegistry::EDependencyCategory::All);
#else
		AssetRegistryModule->Get().GetReferencers(mediaPackageName, dependencies, EAssetRegistryDependencyType::All);
#endif

		if ((dependencies.Num() == 1 && dependencies[0] == assetPackageName) || dependencies.Num() == 0)
		{
			AssetDataToDelete.Emplace(media.LoadSynchronous());
		}
	}
}

void AkAssetDatabase::RenameLocalizedAssets(const UAkAudioEvent* AkAudioEvent, const FString& ParentPath, const FString& AssetName, TArray<FAssetRenameData>& AssetsToRename)
{
	auto LocalizedAssetPath = AkUnrealHelper::GetLocalizedAssetPackagePath();
	for (auto& Entry : AkAudioEvent->LocalizedPlatformAssetDataMap)
	{
		auto LocalizedPackagePath = ObjectTools::SanitizeObjectPath(FPaths::Combine(LocalizedAssetPath, Entry.Key, ParentPath));
		auto NewLocalizedAssetPath = FPaths::Combine(LocalizedPackagePath, AssetName + TEXT(".") + AssetName);
		AssetsToRename.Emplace(Entry.Value, FSoftObjectPath(NewLocalizedAssetPath));
	}
}

bool AkAssetDatabase::IsAkAudioType(const FAssetData& AssetData)
{
	static const TArray<FName> AkAudioClassNames = {
		UAkAcousticTexture::StaticClass()->GetFName(),
		UAkAudioBank::StaticClass()->GetFName(),
		UAkAudioEvent::StaticClass()->GetFName(),
		UAkAuxBus::StaticClass()->GetFName(),
		UAkInitBank::StaticClass()->GetFName(),
		UAkRtpc::StaticClass()->GetFName(),
		UAkStateValue::StaticClass()->GetFName(),
		UAkSwitchValue::StaticClass()->GetFName(),
		UAkTrigger::StaticClass()->GetFName(),
		UAkFolder::StaticClass()->GetFName()

	};

	if (AkAudioClassNames.Contains(AssetData.AssetClass))
		return true;

	return false;

}

void AkAssetDatabase::OnAssetAdded(const FAssetData& NewAssetData)
{
	if (IsAkAudioType(NewAssetData))
	{
		auto AssetID = NewAssetData.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));
		if (AssetID.IsValid())
		{
			if (AkUnrealHelper::IsUsingEventBased() && NewAssetData.GetClass() != UAkAudioBank::StaticClass())
			{
				if (IgnoreAdds.Contains(AssetID))
				{
					return;
				}
				FString AssetBaseFolder = AkAssetDatabase::Get().GetBaseFolderForAssetType(NewAssetData.GetClass());
				FString AssetBasePath = FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), AssetBaseFolder);
				auto NewPath = NewAssetData.ObjectPath.ToString();

				FString AddErrorMessage;
				bool bAddSucceeded = true;

				if (auto FoundAkAudioTypeIt = AudioTypeMap.Find(AssetID))
				{
					TMultiMap<FName, FString> Search;
					TArray<FAssetData> SearchResults;
					Search.Add(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID), AssetID.ToString(EGuidFormats::Digits));
					bool bSuccess = AssetRegistryModule->Get().GetAssetsByTagValues(Search, SearchResults);
					if (bSuccess)
					{
						for (const FAssetData& FoundAsset : SearchResults) 
						{
							FString FoundAssetPath = FoundAsset.ObjectPath.ToString();
							if (FoundAssetPath != NewPath)
							{
								AddErrorMessage = FString::Printf(TEXT("An asset with ID '%s' already exists here '%s"), *AssetID.ToString(EGuidFormats::DigitsWithHyphensInBraces), *FoundAssetPath);
								bAddSucceeded = false;
								break;
							}
						}
					}
				}

				if (!AssetBaseFolder.IsEmpty() && !NewPath.StartsWith(AssetBasePath, ESearchCase::IgnoreCase))
				{
					AddErrorMessage = FString::Printf(TEXT("Asset is not contained within '%s'"), *AssetBasePath);
					bAddSucceeded = false;
				}

				if (!bAddSucceeded)
				{
					const FFormatNamedArguments Args
					{
						{ TEXT("NewPath"), FText::FromString(NewPath) },
						{ TEXT("Reason"), FText::FromString(AddErrorMessage) }
					};

					FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetDatabase", "CannotCreateAsset", "Cannot create asset in '{NewPath}'.\nReason: {Reason}."), Args));
					CopiedAssetsToUndo.Add(NewAssetData);
					return;
				}
			}

			Add(AssetID, NewAssetData);
		}
		else 
		{
			UE_LOG(LogAkAssetDatabase, Verbose, TEXT("Wwise asset %s has invalid GUID"), *NewAssetData.AssetName.ToString());
		}
	}
}

void AkAssetDatabase::onAssetRemoved(const FAssetData& RemovedAssetData)
{
	if (RemovedAssetData.GetClass()->IsChildOf<UAkAudioType>())
	{
		auto assetID = RemovedAssetData.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));
		if (assetID.IsValid())
		{
			Remove(RemovedAssetData);
		}
	}
}

void AkAssetDatabase::onAssetRenamed(const FAssetData& NewAssetData, const FString& OldPath)
{
	static const auto InvalidCharacters = FString(TEXT(":<>*?\"\\/|.%"));

	if (!AkUnrealHelper::IsUsingEventBased())
	{
		return;
	}

	auto assetID = NewAssetData.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));

	if (!assetID.IsValid())
	{
		return;
	}

	if (ignoreRenames.Contains(assetID))
	{
		ignoreRenames.Remove(assetID);
		return;
	}

	auto newPath = NewAssetData.ObjectPath.GetPlainNameString();

	FString oldDirectory;
	FString oldFileName;
	FString oldExtension;
	FPaths::Split(OldPath, oldDirectory, oldFileName, oldExtension);

	FString newDirectory;
	FString newFileName;
	FString newExtension;
	FPaths::Split(newPath, newDirectory, newFileName, newExtension);

	FString assetBaseFolder = AkAssetDatabase::Get().GetBaseFolderForAssetType(NewAssetData.GetClass());
	FString assetBasePath = FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), assetBaseFolder);

	FString moveErrorMessage;
	auto moveSucceeded = true;

	auto invalidName = false;

	if (!assetBaseFolder.IsEmpty() && !newDirectory.StartsWith(assetBasePath, ESearchCase::IgnoreCase))
	{
		moveErrorMessage = FString::Printf(TEXT("Asset is not contained within '%s'"), *assetBasePath);
		moveSucceeded = false;
	}

	if (newFileName.Len() > 0 && !FChar::IsAlpha(newFileName[0]))
	{
		invalidName = true;
	}

	for (auto character : newFileName)
	{
		int32 dummy = 0;
		if (InvalidCharacters.FindChar(character, dummy))
		{
			invalidName = true;
			break;
		}
	}
	IgnoreDeleteOnAssetMove(assetID);

	if (moveSucceeded && !invalidName)
	{
		onAssetUpdated(NewAssetData);
		return;
	}

	if (!moveSucceeded)
	{
		const FFormatNamedArguments Args
		{
			{ TEXT("OldName"), FText::FromString(oldFileName) },
			{ TEXT("OldPath"), FText::FromString(oldDirectory) },
			{ TEXT("NewPath"), FText::FromString(newDirectory) },
			{ TEXT("Reason"), FText::FromString(moveErrorMessage) }
		};

		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetDatabase", "CannotMoveAsset", "Cannot move '{OldName}' from '{OldPath}' to '{NewPath}'. Reason: {Reason}."), Args));
	}
	else if (invalidName)
	{
		const FFormatNamedArguments Args
		{
			{ TEXT("NewName"), FText::FromString(newFileName) },
			{ TEXT("InvalidChars"), FText::FromString(InvalidCharacters) }
		};

		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("AkAssetDatabase", "InvalidAssetName", "Invalid characters found in the new name '{NewName}'. The name must start with a letter and must not contains these characters\n\n{InvalidChars}"), Args));
	}

	ignoreRenames.Add(assetID);
	// This is required to avoid an assert in RenameAssets() when the asset is referenced somewhere
	GRedirectCollector.AddAssetPathRedirection(FName(*OldPath), FName(*newPath));

	FAssetRenameData renameData{ NewAssetData.ToSoftObjectPath(), FSoftObjectPath(OldPath) };
	
	WaapiAssetSynchronizer::PauseAssetRegistryDelegates = true;
	AssetToolsModule->Get().RenameAssets(TArray<FAssetRenameData>{renameData});
	WaapiAssetSynchronizer::PauseAssetRegistryDelegates = false;

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	ContentBrowserModule.Get().SyncBrowserToAssets({ FAssetData(FSoftObjectPath(OldPath).TryLoad()) });
}

bool AkAssetDatabase::CheckIfLoadingAssets()
{
	bool isLoadingAssets = AssetRegistryModule->Get().IsLoadingAssets();
	return isLoadingAssets;
}

void AkAssetDatabase::onAssetUpdated(const FAssetData& UpdatedAssetData)
{
	if (IsAkAudioType(UpdatedAssetData))
	{
		auto assetID = UpdatedAssetData.GetTagValueRef<FGuid>(GET_MEMBER_NAME_CHECKED(UAkAudioType, ID));
		if (assetID.IsValid())
		{
			if (auto foundAssetData = AudioTypeMap.Find(assetID))
			{
				*foundAssetData = UpdatedAssetData;
			}

			UClass* assetKlass = UpdatedAssetData.GetClass();

			if (assetKlass->IsChildOf<UAkAcousticTexture>())
			{
				if (auto foundAcousticTexture = AcousticTextureMap.Find(assetID))
				{
					*foundAcousticTexture = UpdatedAssetData;
				}
				else
				{
					Add(assetID, UpdatedAssetData);
				}
			}
			else if (assetKlass->IsChildOf<UAkAudioEvent>())
			{
				if (auto foundEvent = EventMap.Find(assetID))
				{
					*foundEvent = UpdatedAssetData;
				}
				else
				{
					Add(assetID, UpdatedAssetData);
				}
			}
			else if (assetKlass->IsChildOf<UAkAuxBus>())
			{
				if (auto foundAuxBus = AuxBusMap.Find(assetID))
				{
					*foundAuxBus = UpdatedAssetData;
				}
				else
				{
					Add(assetID, UpdatedAssetData);
				}
			}
			else if (assetKlass->IsChildOf<UAkGroupValue>())
			{
				if (auto foundGroupValue = GroupValueMap.Find(assetID))
				{
					*foundGroupValue = UpdatedAssetData;
				}
				else
				{
					Add(assetID, UpdatedAssetData);
				}
			}
			else if (assetKlass->IsChildOf<UAkTrigger>())
			{
				if (auto foundTrigger = TriggerMap.Find(assetID))
				{
					*foundTrigger = UpdatedAssetData;
				}
				else
				{
					Add(assetID, UpdatedAssetData);
				}
			}
			else if (assetKlass->IsChildOf<UAkRtpc>())
			{
				if (auto foundRtpc = RtpcMap.Find(assetID))
				{
					*foundRtpc = UpdatedAssetData;
				}
				else
				{
					Add(assetID, UpdatedAssetData);
				}
			}
			else if (assetKlass->IsChildOf<UAkAudioBank>())
			{
				if (auto foundBank = BankMap.Find(assetID))
				{
					*foundBank = UpdatedAssetData;
				}
				else
				{
					Add(assetID, UpdatedAssetData);
				}
			}
			else if (assetKlass->IsChildOf<UAkFolder>())
			{
				if (auto foundBank = FolderMap.Find(assetID))
				{
					*foundBank = UpdatedAssetData;
				}
				else
				{
					Add(assetID, UpdatedAssetData);
				}
			}
		}
	}
}

bool AkAssetDatabase::Tick(float DeltaTime)
{
	if (CopiedAssetsToUndo.Num() > 0)
	{
		ObjectTools::DeleteAssets(CopiedAssetsToUndo, false);
		CopiedAssetsToUndo.Empty();
	}

	checkFoldersToRemove();
	return true;
}

void AkAssetDatabase::IgnoreDeleteOnAssetMove(FGuid id)
{
	ignoreDeletes.Add(id);
}

void AkAssetDatabase::IgnoreAddOnAssetMove(FGuid id)
{
	IgnoreAdds.Add(id);
}


#undef LOCTEXT_NAMESPACE
