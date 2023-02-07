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

#include "Containers/Map.h"
#include "Containers/UnrealString.h"
#include "Containers/Ticker.h"
#include "HAL/CriticalSection.h"
#include "Misc/EnumClassFlags.h"
#include "Misc/Guid.h"
#include "Misc/ScopeLock.h"
#include "UObject/SoftObjectPtr.h"
#include "AkMediaAsset.h"
#include "WwiseItemType.h"
#include "AssetData.h"


class FAssetRegistryModule;
class FAssetToolsModule;
class UAkAcousticTexture;
class UAkAudioBank;
class UAkAudioEvent;
class UAkAudioType;
class UAkAuxBus;
class UAkGroupValue;
class UAkInitBank;
class UAkMediaAsset;
class UAkRtpc;
class UAkSettings;
class UAkStateValue;
class UAkSwitchValue;
class UAkTrigger;
class UAkFolder;

struct FAssetRenameData;

template<typename AkAssetType>
struct AkAssetTraits
{
	static const FString Name() { return ""; }
	static const FString BaseFolder() { return ""; };
};

template<>
struct AkAssetTraits<UAkAcousticTexture>
{
	static const FString Name() { return "AcousticTexture"; }
	static const FString BaseFolder() { return "Virtual_Acoustics"; }
};

template<>
struct AkAssetTraits<UAkAudioEvent>
{
	static const FString Name() { return "Event"; }
	static const FString BaseFolder() { return "Events"; }
};

template<>
struct AkAssetTraits<UAkAuxBus>
{
	static const FString Name() { return "AuxBus"; }
	static const FString BaseFolder() { return "Master-Mixer_Hierarchy"; }
};

template<>
struct AkAssetTraits<UAkRtpc>
{
	static const FString Name() { return "GameParameter"; }
	static const FString BaseFolder() { return "Game_Parameters"; }
};

template<>
struct AkAssetTraits<UAkStateValue>
{
	static const FString Name() { return "State"; }
	static const FString BaseFolder() { return "States"; }
};

template<>
struct AkAssetTraits<UAkSwitchValue>
{
	static const FString Name() { return "Switch"; }
	static const FString BaseFolder() { return "Switches"; }
};

template<>
struct AkAssetTraits<UAkTrigger>
{
	static const FString Name() { return "Trigger"; }
	static const FString BaseFolder() { return "Triggers"; }
};

class AkAssetDatabase
{
public:
	static AkAssetDatabase& Get();

	void Init();
	void Clear();

	void ScanForAkAssets();
	void FindInitBank();

	static FString GetBaseFolderForAssetType(const UClass* Klass);
	static bool IsFolderType(const EWwiseItemType::Type ItemType);
	bool IsInWwiseFolderHeirarchy(const FString& AssetPath);
	UAkFolder* GetContainingFolder(const FString& AssetPath);
	FString UpdateWwiseFolderPaths(const FString& AssetPath);
	FString GetWwisePathFromAssetPath(const FString& AssetPath);
	FGuid GetFolderGuid(const FString& AssetPath);


	bool Add(const FGuid& Id, const FAssetData& AssetData);
	bool Remove(const FAssetData& AssetData);

	enum AssetSyncMode
	{
		Filesystem = 0,
		WAAPI = 1
	};

	UPackage* CreateOrRenameAsset(const UClass* Klass, const FGuid& Id, const FString& Name, const FString& AssetName, const FString& RelativePath, const FGuid& GroupId, const AssetSyncMode& syncMode, bool& FoundAsset, bool& AssetModified);
	UObject* CreateOrRenameFolder(const UClass* Klass, const FGuid& Id, const FString& Name, const FString& RelativePath, const EWwiseItemType::Type FolderType, const AssetSyncMode& syncMode, bool& AssetModified);

	void RenameGroupValues(const FGuid& GroupId, const FString& GroupName, const FString& Path);
	void DeleteAsset(const FGuid& Id);
	void DeleteAssets(const TSet<FGuid>& AssetsId);

	void FillAssetsToDelete(FAssetData* Asset, TArray<FAssetData>& AssetDataToDelete);

	void MoveAllAssets(const FString& OldBaseAssetPath, const FString& NewBaseAssetPath);


	void CreateInitBankIfNeeded();

	void FixUpRedirectors(const FString& AssetPackagePath);

	enum class CanBeDroppedSource
	{
		FromPicker,
		FromContentBrowser
	};

	bool CanBeDropped(const FAssetData& AssetData, FName PackagePath, CanBeDroppedSource Source) const;

	bool IsInited() const { return InitBank != nullptr; }
	bool CheckIfLoadingAssets();
	void IgnoreDeleteOnAssetMove(FGuid);
	void IgnoreAddOnAssetMove(FGuid);

public:
	template<typename AkAssetType>
	struct AkTypeMap
	{
		mutable FCriticalSection CriticalSection;
		TMap<FGuid, FAssetData> TypeMap;

		FAssetData* Find(const FGuid& Key)
		{
			FScopeLock autoLock(&CriticalSection);
			return TypeMap.Find(Key);
		}

		FAssetData const* Find(const FGuid& Key) const
		{
			FScopeLock autoLock(&CriticalSection);
			return TypeMap.Find(Key);
		}

		TArray<FAssetData> FindByName(const FString& Name) const
		{
			FScopeLock autoLock(&CriticalSection);

			TArray<FAssetData> FoundAssets;
			for (auto& entry : TypeMap)
			{
				if (entry.Value.AssetName == *Name)
				{
					FoundAssets.Add(entry.Value);
				}
			}

			return FoundAssets;
		}

		AkAssetType* FindLiveAsset(const FGuid& Key) const
		{
			FScopeLock autoLock(&CriticalSection);
			if (auto found = TypeMap.Find(Key))
			{
				return Cast<AkAssetType>(found->GetAsset());
			}

			return nullptr;
		}

		void Add(const FGuid& Key, const FAssetData& AssetData)
		{
			FScopeLock autoLock(&CriticalSection);

			if (!TypeMap.Contains(Key))
			{
				TypeMap.Add(Key, AssetData);
			}
		}

		int32 Remove(const FGuid& Key)
		{
			FScopeLock autoLock(&CriticalSection);
			return TypeMap.Remove(Key);
		}

		int32 RemoveByName(const FString& Name)
		{
			int32 result = 0;
			FScopeLock autoLock(&CriticalSection);

			TSet<FGuid> guidToRemove;
			for (auto& entry : TypeMap)
			{
				if (entry.Value.AssetName == *Name)
				{
					guidToRemove.Add(entry.Key);
				}
			}

			for (auto& guid : guidToRemove)
			{
				result += TypeMap.Remove(guid);
			}

			return result;
		}

		void Empty()
		{
			FScopeLock autoLock(&CriticalSection);
			TypeMap.Empty();
		}
	};

	AkTypeMap<UAkAcousticTexture> AcousticTextureMap;
	AkTypeMap<UAkAudioEvent> EventMap;
	AkTypeMap<UAkAuxBus> AuxBusMap;
	AkTypeMap<UAkAudioBank> BankMap;
	AkTypeMap<UAkGroupValue> GroupValueMap;
	AkTypeMap<UAkTrigger> TriggerMap;
	AkTypeMap<UAkRtpc> RtpcMap;
	AkTypeMap<UAkFolder> FolderMap;

	AkTypeMap<UAkAudioType> AudioTypeMap;
	TSet<FGuid> PendingAssetCreates;
	mutable FCriticalSection InitBankLock;
	UAkInitBank* InitBank = nullptr;
	static const FString TemporaryGroupValueFolder;

private:
	AkAssetDatabase();

	bool IsAkAudioType(const FAssetData& AssetData);

	void OnAssetAdded(const FAssetData& NewAssetData);
	void onAssetRemoved(const FAssetData& RemovedAssetData);
	void onAssetRenamed(const FAssetData& NewAssetData, const FString& OldPath);
	void onAssetUpdated(const FAssetData& UpdatedAssetData);
	void processMediaToDelete(UObject* Asset, const TArray<TSoftObjectPtr<UAkMediaAsset>>& MediaList, TArray<FAssetData>& AssetDataToDelete);
	void RenameLocalizedAssets(const UAkAudioEvent* akAudioEvent, const FString& parentPath, const FString& AssetName, TArray<FAssetRenameData>& assetsToRename);
	void moveFolder(const FString& OldPath, const UAkFolder* newFolder, TArray<FAssetRenameData> assetsToRename);
	void moveFolder(const FString& ObjectPath, const FString& OldPath, const FString& newFolder, TArray<FAssetRenameData> assetsToRename);
	void checkFoldersToRemove();
	void removeFolder(const FGuid& FolderAssetGuid);
	void removeFolder(const FString& RelativePath);
	void removeFolders(const TSet<FString>& folders);

private:
	FAssetRegistryModule* AssetRegistryModule = nullptr;
	FAssetToolsModule* AssetToolsModule = nullptr;

	TSet<FGuid> ignoreRenames;
	TSet<FGuid> ignoreDeletes;
	TSet<FGuid> IgnoreAdds;


	TArray<FAssetData> CopiedAssetsToUndo;
	FTickerDelegate OnTick;
	FTickerDelegateHandle TickDelegateHandle;
	bool Tick(float DeltaTime);
	TSet<FString> FoldersPendingRemoval;
};
