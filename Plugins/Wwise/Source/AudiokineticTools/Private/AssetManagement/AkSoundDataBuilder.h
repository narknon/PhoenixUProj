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

#include "AssetData.h"
#include "Async/TaskGraphInterfaces.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "Containers/Set.h"
#include "Containers/UnrealString.h"
#include "HAL/CriticalSection.h"
#include "Serialization/JsonSerializer.h"
#include "Templates/SharedPointer.h"
#include "UObject/SoftObjectPath.h"
#include "UObject/SoftObjectPtr.h"
#include "WwiseProject/WwiseProjectInfo.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "AkUnrealHelper.h"


struct FStreamableHandle;

class FAssetRegistryModule;
class FAssetToolsModule;
class FJsonObject;
class IPlatformFile;
class ISoundBankInfoCache;
class SNotificationItem;
class UAkAssetData;
class UAkAssetDataSwitchContainer;
class UAkAssetDataSwitchContainerData;
class UAkAssetDataWithMedia;
class UAkAudioBank;
class UAkAudioEvent;
class UAkAudioEventData;
class UAkAuxBus;
class UAkAuxBusPlatformData;
class UAkGroupValue;
class UAkInitBank;
class UAkInitBankPlatformData;
class UAkMediaAsset;
class UAkMediaAssetData;
class UAkRtpc;
class UAkTrigger;
class UAkAssetBase;
class UPackage;

struct MediaAssetPerPlatformData
{
	bool IsStreamed = false;
	bool UseDeviceMemory = false;
	uint32 PrefetchSize = 0;
	FString Platform;
};

struct MediaAssetToCook
{
	FSoftObjectPath AssetPath;
	uint32 Id = 0;
	FString Language;
	FString CachePath;
	FString MediaName;
	TMap<FString, MediaAssetPerPlatformData> ParsedPerPlatformData;
	UAkMediaAsset* Instance = nullptr;
	UAkMediaAssetData* CurrentPlatformData = nullptr;
	bool AutoLoad = false;
};

struct AutoSetIsBuilding
{
	AutoSetIsBuilding();
	~AutoSetIsBuilding();
};

struct AudioBankInfoEntry
{
	TSet<FString> Events;
	TSet<FString> AuxBusses;
	bool NeedsRebuild = false;
};


//Map language to ID map
using MediaIdMap = TMap<uint32, TSharedPtr<MediaAssetToCook>>;
using MediaToCookMap = TMap<FString, MediaIdMap>;
using AudioBankInfoMap = TMap<FString, AudioBankInfoEntry>;
using MediaDependencySet = TSet<TSoftObjectPtr<UAkMediaAsset>>;
using GroupValueMediaDependencyMap = TMap<UAkGroupValue*, MediaDependencySet>;

DECLARE_STATS_GROUP(TEXT("AkSoundDataBuilder"), STATGROUP_AkSoundDataSource, STATCAT_Audiokinetic);

class AkSoundDataBuilder : public TSharedFromThis<AkSoundDataBuilder, ESPMode::ThreadSafe>
{
public:
	struct InitParameters
	{
		TArray<FString> Platforms;
		TArray<FWwiseLanguageInfo> Languages;
		TSet<FString> BanksToGenerate;
		bool SkipLanguages = false;
	};

	AkSoundDataBuilder(const InitParameters& InitParameter);
	virtual ~AkSoundDataBuilder();

	virtual void Init();

	virtual void DoWork() = 0;

	TSet<UPackage*>& SaveAssetsBlocking();

	friend class AkEventBasedToolBehavior;
	friend class AkLegacyToolBehavior;

protected:
	void createNotificationItem();
	void notifyGenerationFailed();
	void notifyCookingData();
	void notifyGenerationSucceeded();
	void notifyProfilingInProgress();
	void WrapUpGeneration(const bool& bSuccess, const FString& BuilderName);

	bool ProcessMediaEntry(const FString& platform, TMap<uint32, TSoftObjectPtr<UAkMediaAsset>>& NewMediaMap, const TSharedPtr<FJsonObject>& MediaData, bool bIsStreamed);

	bool ParseMedia(const TSharedPtr<FJsonObject>& soundBankJson, TMap<uint32, TSoftObjectPtr<UAkMediaAsset>>& MediaMap, const FString& platform);
	void ParseGameSyncs(const TSharedPtr<FJsonObject>& soundBankJson);
	bool ParseBankHash(UAkAssetData* bankData, const TSharedPtr<FJsonObject>& soundBankJson);

	bool MediaListsAreDifferent(const TArray<TSoftObjectPtr<UAkMediaAsset>>& OldList, const TArray<TSoftObjectPtr<UAkMediaAsset>>& NewList);
	bool DidSwitchContainerDataChange(const TArray<UAkAssetDataSwitchContainerData*>& OldData, const TArray<UAkAssetDataSwitchContainerData*>& NewData);
	bool ParseMediaAndSwitchContainers(TSharedPtr<FJsonObject> eventJson, UAkAssetDataSwitchContainer* AssetData, const FString& platform, const FString& Language);

	template<typename AssetType>
	bool ParseEventMetadataSection(TSharedPtr<FJsonObject> eventJson, const FString& SectionName, const AkAssetDatabase::AkTypeMap<AssetType>* AssetMap, TSet<AssetType*>* DestinationSet);

	bool ParseSoundBankInfo(UAkAssetBase* mainAsset, UAkAssetData* platformAsset, const FString& platform, const FString& language, const TSharedPtr<FJsonObject>& soundBankJson);

	bool ParseEventAssetInfo(UAkAudioEvent* AkEvent, UAkAssetData* PlatformData, const FString& Platform, const FString& Language, const TSharedPtr<FJsonObject>& SoundBankJson);
	bool ParseAuxBusAssetInfo(UAkAuxBus* akAuxBus, UAkAssetData* auxBusPlatformData, const FString& platform, const FString& language, const TSharedPtr<FJsonObject>& SoundBankJson);
	bool ParseInitBankAssetInfo(UAkInitBank* AkInitBank, const TSharedPtr<FJsonObject>& SoundBankJson);
	bool ParseAudioBankAssetInfo(UAkAudioBank* AkAudioBank, const FString& Platform, const FString& Language, const TSharedPtr<FJsonObject>& SoundBankJson);

	bool GetAuxBusFromBankInfo(const TSharedPtr<FJsonObject>& SoundBankJson);

	bool ParseEventInfo(UAkAudioEvent* akEvent, UAkAudioEventData* eventPlatformData, const TSharedPtr<FJsonObject>& eventJson);

	void parseGroupValue(const TSharedPtr<FJsonObject>& groupValueObject, uint32 groupId);

	/**
	 * Parses the Switch Container JSON metadata, and adds the medias in the proper UAkAssetDataSwitchContainerData's media list
	 *
	 * @param SwitchContainerJson			The JSON metadata generated by Wwise
	 * @param InOutSwitchContainerData		Array of UAkAssetDataSwitchContainerData, contained either in the parent UAkAudioEvent, or a child UAkAssetDataSwitchContainerData (in the case of nested switch containers)
	 * @param InOutEventMedia				Parent media map. At first, contains all media referenced by the parent, but as we parse switch values, medias will be removed from this map to be added to the proper
	 * 										UAkAssetDataSwitchContainerData's media list.
	 * @param InOutParent					Parent object. Either a UAkAudioEvent, or another UAkAssetDataSwitchContainerData in case of nested switch containers
	 * @param Platform						The event's platform
	 * @param Language						The event's language (a.k.a. localization)
	 */
	void ParseSwitchContainer(const TSharedPtr<FJsonObject>& SwitchContainerJson, TArray<UAkAssetDataSwitchContainerData*>& InOutSwitchContainerData, TMap<uint32, TSoftObjectPtr<UAkMediaAsset>>& InOutEventMedia, UObject* InOutParent, const FString& Platform, const FString& Language);


	void parseGameParameter(const TSharedPtr<FJsonObject>& gameParameterObject);
	void parseTrigger(const TSharedPtr<FJsonObject>& triggerObject);

	bool parsePluginInfo(UAkInitBank* initBank, const FString& platform, const TSharedPtr<FJsonObject>& pluginInfoJson);

	void CookMediaAsset(MediaAssetToCook& assetToCook, const FString& platform);

	void DispatchAndWaitMediaCookTasks();

	void MarkAssetDirty(UObject* Obj);

	enum class FillAudioBankInfoKind
	{
		GUID,
		AssetName
	};
	FString fillAudioBankInfoMap(AudioBankInfoMap& AudioBankInfoMap, FillAudioBankInfoKind InfoKind, const TSet<FString>& PlatformsToBuild, const TSet<FString>& LanguagesToBuild, ISoundBankInfoCache* SoundBankInfoCache);

	bool fillBankDataInAsset(UAkAssetData* AssetData, const TArray<uint8>& NewBankData, FCriticalSection* DataLock);

	void LoadAndWaitForAssetToLoad();

private:
	void DispatchMediaCookTask(const MediaToCookMap& MediaMap, const FString& Platform);

	MediaToCookMap& GetMediaToCookMap(const FString& Platform)
	{
		FScopeLock AutoLock(&MediaLock);
		return MediaToCookPerPlatform.FindOrAdd(Platform);
	}

protected:
	FAssetRegistryModule* AssetRegistryModule = nullptr;
	FAssetToolsModule* AssetToolsModule = nullptr;

	FString BasePackagePath;
	FString LocalizedPackagePath;
	FString CacheDirectory;
	FString DefaultLanguage;

	InitParameters initParameters;

	bool SplitSwitchContainerMedia = false;
	bool SplitMediaPerFolder = false;

	TSharedPtr<SNotificationItem> notificationItem;
	TArray<TSharedPtr<FStreamableHandle>> LoadedAssetsHandles;

	IPlatformFile* platformFile = nullptr;

	WwiseProjectInfo WwiseProjectInfo;

	TSet<UPackage*> PackagesToSave;

	FCriticalSection ParseTasksLock;
	FGraphEventArray AllParseTask;

	FGraphEventArray PostParseTasks;

	FThreadSafeBool bParsingMediaMap;

	uint64 StartTime;

private:
	mutable FCriticalSection MediaLock;
	TMap<FString, MediaToCookMap> MediaToCookPerPlatform;
	FGraphEventArray AllMediaTasks;
	TSet<UAkAssetDataWithMedia*> AllMediaData;
	TSet<TSoftObjectPtr<UAkMediaAsset>> MediaAssetsInSwitchContainersMissingGroupValues;

	// Used during sound data generation to gather all media files that a group value has a reference to.
	mutable FCriticalSection MediaDependenciesLock;
	GroupValueMediaDependencyMap TempMediaDependenciesList;
};
