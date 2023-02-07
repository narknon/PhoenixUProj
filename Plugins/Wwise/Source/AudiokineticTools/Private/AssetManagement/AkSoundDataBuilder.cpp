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

#include "AkSoundDataBuilder.h"

#include "AkAssetDatabase.h"
#include "AkAudioBank.h"
#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioDevice.h"
#include "AkAudioEvent.h"
#include "AkAudioStyle.h"
#include "AkAuxBus.h"
#include "AkGroupValue.h"
#include "AkInitBank.h"
#include "AkMediaAsset.h"
#include "AkRtpc.h"
#include "AkSettings.h"
#include "AkSwitchValue.h"
#include "AkTrigger.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "AssetTools/Public/AssetToolsModule.h"
#include "Async/Async.h"
#include "Async/ParallelFor.h"
#include "Core/Public/Hash/CityHash.h"
#include "Editor.h"
#include "Framework/Docking/TabManager.h"
#include "Framework/Notifications/NotificationManager.h"
#include "HAL/FileManager.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "Misc/Paths.h"
#include "Misc/ScopedSlowTask.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "StaticPluginWriter.h"
#include "ToolBehavior/AkToolBehavior.h"
#include "UnrealEd/Public/FileHelpers.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "UnrealEd/Public/ObjectTools.h"

#define LOCTEXT_NAMESPACE "AkAudio"

DECLARE_CYCLE_STAT(TEXT("AkSoundData - Gather Assets"), STAT_GatherAssets, STATGROUP_AkSoundDataSource);
DECLARE_CYCLE_STAT(TEXT("AkSoundData - Gather Media Assets"), STAT_GatherMediaAssets, STATGROUP_AkSoundDataSource);
DECLARE_CYCLE_STAT(TEXT("AkSoundData - Cook Media Asset"), STAT_CookMediaAsset, STATGROUP_AkSoundDataSource);
DECLARE_CYCLE_STAT(TEXT("AkSoundData - Fetch Event Platform Data For Event Group"), STAT_EventPlatformDataEventGroup, STATGROUP_AkSoundDataSource);
DECLARE_CYCLE_STAT(TEXT("AkSoundData - Parse Event Info For Event Group"), STAT_ParseEventInfoEventGroup, STATGROUP_AkSoundDataSource);
DECLARE_CYCLE_STAT(TEXT("AkSoundData - Auto Save assets"), STAT_AutoSaveAssets, STATGROUP_AkSoundDataSource);

namespace AkSoundDataBuilder_Helpers
{
	constexpr auto SoundBankNamePrefix = TEXT("SB_");
}

AutoSetIsBuilding::AutoSetIsBuilding()
{
	if (FAkAudioDevice::Get())
	{
		FAkAudioDevice::Get()->IsBuildingData = true;
	}
}

AutoSetIsBuilding::~AutoSetIsBuilding()
{
	if (FAkAudioDevice::Get())
	{
		FAkAudioDevice::Get()->IsBuildingData = false;
	}
}

AkSoundDataBuilder::AkSoundDataBuilder(const InitParameters& InitParameter)
	: initParameters(InitParameter)
{
	platformFile = &FPlatformFileManager::Get().GetPlatformFile();
	TempMediaDependenciesList.Empty();
}

AkSoundDataBuilder::~AkSoundDataBuilder()
{
	for (auto& Handle : LoadedAssetsHandles)
	{
		Handle->ReleaseHandle();
	}
}

void AkSoundDataBuilder::Init()
{
	AssetRegistryModule = &FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	AssetToolsModule = &FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");

	BasePackagePath = AkUnrealHelper::GetBaseAssetPackagePath();
	LocalizedPackagePath = AkUnrealHelper::GetLocalizedAssetPackagePath();

	if (auto AkSettings = GetDefault<UAkSettings>())
	{
		SplitSwitchContainerMedia = AkSettings->SplitSwitchContainerMedia;
		SplitMediaPerFolder = AkSettings->SplitMediaPerFolder;
	}

	WwiseProjectInfo.Parse();

	CacheDirectory = WwiseProjectInfo.GetCacheDirectory();
	DefaultLanguage = WwiseProjectInfo.GetDefaultLanguage();

	auto& AssetDatabase = AkAssetDatabase::Get();
	if (!AssetDatabase.IsInited())
	{
		AssetDatabase.Init();
		AssetDatabase.ScanForAkAssets();
	}

	{
		FScopeLock AutoLock(&AssetDatabase.InitBankLock);
		if (AssetDatabase.InitBank->DefaultLanguage != DefaultLanguage)
		{
			AssetDatabase.InitBank->DefaultLanguage = DefaultLanguage;
			MarkAssetDirty(AssetDatabase.InitBank);
		}
	}

	bParsingMediaMap = false;
}

void AkSoundDataBuilder::createNotificationItem()
{
	if (!IsRunningCommandlet())
	{
		AsyncTask(ENamedThreads::Type::GameThread, [sharedThis = SharedThis(this)]
			{
				FNotificationInfo Info(LOCTEXT("GeneratingSoundData", "Generating Wwise sound data..."));

				Info.Image = FAkAudioStyle::GetBrush(TEXT("AudiokineticTools.AkPickerTabIcon"));
				Info.bFireAndForget = false;
				Info.FadeOutDuration = 0.0f;
				Info.ExpireDuration = 0.0f;
	#if UE_4_26_OR_LATER
				Info.Hyperlink = FSimpleDelegate::CreateLambda([]() { FGlobalTabmanager::Get()->TryInvokeTab(FName("OutputLog")); });
	#else
				Info.Hyperlink = FSimpleDelegate::CreateLambda([]() { FGlobalTabmanager::Get()->InvokeTab(FName("OutputLog")); });
	#endif
				Info.HyperlinkText = LOCTEXT("ShowOutputLogHyperlink", "Show Output Log");
				sharedThis->notificationItem = FSlateNotificationManager::Get().AddNotification(Info);
			});
	}
}

void AkSoundDataBuilder::notifyGenerationFailed()
{
	if (!IsRunningCommandlet())
	{
		AsyncTask(ENamedThreads::Type::GameThread, [sharedThis = SharedThis(this)]
			{
				if (sharedThis->notificationItem)
				{
					sharedThis->notificationItem->SetText(LOCTEXT("SoundDataGenerationFailed", "Generating Wwise sound data failed!"));

					sharedThis->notificationItem->SetCompletionState(SNotificationItem::CS_Fail);
					sharedThis->notificationItem->SetExpireDuration(3.5f);
					sharedThis->notificationItem->SetFadeOutDuration(0.5f);
					sharedThis->notificationItem->ExpireAndFadeout();
				}

				GEditor->PlayEditorSound(TEXT("/Engine/EditorSounds/Notifications/CompileFailed_Cue.CompileFailed_Cue"));
			});
	}
}

void AkSoundDataBuilder::notifyProfilingInProgress()
{
	if (!IsRunningCommandlet())
	{
		AsyncTask(ENamedThreads::Type::GameThread, [sharedThis = SharedThis(this)]
			{
				if (sharedThis->notificationItem)
				{
					sharedThis->notificationItem->SetText(LOCTEXT("SoundDataGenerationProfiling", "Cannot generate sound data while Authoring is profiling."));

					sharedThis->notificationItem->SetCompletionState(SNotificationItem::CS_Fail);
					sharedThis->notificationItem->SetExpireDuration(3.5f);
					sharedThis->notificationItem->SetFadeOutDuration(0.5f);
					sharedThis->notificationItem->ExpireAndFadeout();
				}

				GEditor->PlayEditorSound(TEXT("/Engine/EditorSounds/Notifications/CompileFailed_Cue.CompileFailed_Cue"));
			});
	}
}

void AkSoundDataBuilder::WrapUpGeneration(const bool& bSuccess, const FString& BuilderName)
{
	FTaskGraphInterface::Get().WaitUntilTasksComplete(AllParseTask);
	FTaskGraphInterface::Get().WaitUntilTasksComplete(PostParseTasks);

	DispatchAndWaitMediaCookTasks();

	for (TObjectIterator<UAkAudioType> AudioTypeIt; AudioTypeIt; ++AudioTypeIt)
	{
		AudioTypeIt->ValidateShortId(true);
	}

	FString SuccessMessage;

	if (!bSuccess)
	{
		SuccessMessage = BuilderName + TEXT(" Sound Data Builder task failed");
		notifyGenerationFailed();
	}
	else
	{
		SuccessMessage = BuilderName + TEXT(" Sound Data Builder task was successful");
		notifyGenerationSucceeded();
	}

	if (!IsRunningCommandlet())
	{
		AsyncTask(ENamedThreads::Type::GameThread, []
			{
				if (FAkAudioDevice* AudioDevice = FAkAudioDevice::Get())
				{
					AudioDevice->ReloadAllSoundData();
				}
			});
	}

	auto EndTime = FPlatformTime::Cycles64();
	UE_LOG(LogAkSoundData, Display, TEXT("%s and took %f seconds."), *SuccessMessage, FPlatformTime::ToSeconds64(EndTime - StartTime));
}

void AkSoundDataBuilder::notifyCookingData()
{
	if (!IsRunningCommandlet())
	{
		AsyncTask(ENamedThreads::Type::GameThread, [sharedThis = SharedThis(this)]
			{
				if (sharedThis->notificationItem)
				{
					sharedThis->notificationItem->SetCompletionState(SNotificationItem::CS_Pending);
					sharedThis->notificationItem->SetText(LOCTEXT("CookingSoundData", "Cooking Wwise sound data into the assets..."));
				}
			});
	}
}

void AkSoundDataBuilder::notifyGenerationSucceeded()
{
	if (!IsRunningCommandlet())
	{
		AsyncTask(ENamedThreads::Type::GameThread, [sharedThis = SharedThis(this)]
			{
				if (sharedThis->notificationItem)
				{
					sharedThis->notificationItem->SetText(LOCTEXT("CookingSoundDataCompleted", "Cooking Wwise sound data completed!"));

					sharedThis->notificationItem->SetCompletionState(SNotificationItem::CS_Success);
					sharedThis->notificationItem->SetExpireDuration(3.5f);
					sharedThis->notificationItem->SetFadeOutDuration(0.5f);
					sharedThis->notificationItem->ExpireAndFadeout();
				}

				GEditor->PlayEditorSound(TEXT("/Engine/EditorSounds/Notifications/CompileSuccess_Cue.CompileSuccess_Cue"));
			});
	}
}

bool AkSoundDataBuilder::ProcessMediaEntry(const FString& Platform, TMap<uint32, TSoftObjectPtr<UAkMediaAsset>>& NewMediaMap, const TSharedPtr<FJsonObject>& MediaData, bool bIsStreamed)
{
	FString StringId = MediaData->GetStringField("Id");

	uint32 Id = FCString::Atoi64(*StringId);

	FString Language = MediaData->GetStringField("Language");

	FString CachePath = MediaData->GetStringField("Path");

	FString MediaName = FPaths::GetBaseFilename(MediaData->GetStringField("ShortName"));

	FSoftObjectPath AssetPath;
	bool bUseDeviceMemory = false;
	FString StringUseDeviceMemory;
	if (MediaData->TryGetStringField(TEXT("UseDeviceMemory"), StringUseDeviceMemory))
	{
		bUseDeviceMemory = (StringUseDeviceMemory == TEXT("true"));
	}

	bool bUsingReferenceLanguageAsStandIn = false;
	if (MediaData->TryGetBoolField(TEXT("UsingReferenceLanguageAsStandIn"), bUsingReferenceLanguageAsStandIn) && bUsingReferenceLanguageAsStandIn)
	{
		UE_LOG(LogAkAudio, Log, TEXT("Media %s for language %s is using a copy of default langauge (%s) media. Id : %s"), *MediaName, *Language, *DefaultLanguage, *StringId);
	}

	bool changed = false;

	FString SubFolder;
	if (SplitMediaPerFolder)
	{
		SubFolder = FString::Printf(TEXT("%02x/%02x"), (Id >> 24) & 0xFF, (Id >> 16) & 0xFF);
	}

	if (Language != TEXT("SFX"))
	{
		AssetPath = ObjectTools::SanitizeObjectPath(FPaths::Combine(LocalizedPackagePath, Language, AkUnrealHelper::MediaFolderName, SubFolder, StringId + TEXT(".") + StringId));
	}
	else
	{
		AssetPath = ObjectTools::SanitizeObjectPath(FPaths::Combine(BasePackagePath, AkUnrealHelper::MediaFolderName, SubFolder, StringId + TEXT(".") + StringId));
	}

	bool bIsInNewMediaMap =true;
	if (!NewMediaMap.Contains(Id))
	{
		bIsInNewMediaMap =false;
		NewMediaMap.Add(Id, TSoftObjectPtr<UAkMediaAsset>(AssetPath));
		changed = true;
	}

	{
		FScopeLock AutoLock(&MediaLock);
		check(!bParsingMediaMap);

		MediaToCookMap& CookMap = GetMediaToCookMap(Platform);
		MediaIdMap& MediaMap = CookMap.FindOrAdd(Language);
		auto* MediaAssetToCookIt = MediaMap.Find(Id);
		if (MediaAssetToCookIt)
		{
			MediaAssetPerPlatformData& ParsedPlatformData = MediaAssetToCookIt->Get()->ParsedPerPlatformData.FindOrAdd(Platform);

			FString stringPrefetchSize;
			if (MediaData->TryGetStringField("PrefetchSize", stringPrefetchSize))
			{
				uint32 ParsedPrefetchSize = static_cast<uint32>(FCString::Atoi(*stringPrefetchSize));

				ParsedPlatformData.PrefetchSize = FMath::Max(ParsedPlatformData.PrefetchSize, ParsedPrefetchSize);
			}

			ParsedPlatformData.UseDeviceMemory = bUseDeviceMemory;

			//In the future, if we want to support both streamed and not streamed at the same time, we'd need to create a second asset
			//Streamed media is in both streaming media list and in excluded media list so we don't want to log this when we're "correctly" parsing it for the second time.
			if (ParsedPlatformData.IsStreamed != bIsStreamed && !bIsInNewMediaMap)
			{
				UE_LOG(LogAkAudio, Error, 
					TEXT("Media %s - %u has been parsed as both streaming and in-memory. It will be cooked to have streaming functionality, and will not be loaded into memory. Events expecting this media to be in memory will throw a 'Media not found' error.")
					, *MediaName, Id)
			}

			ParsedPlatformData.IsStreamed = bIsStreamed ? true : ParsedPlatformData.IsStreamed;
			ParsedPlatformData.Platform = Platform;
		}
		else
		{
			auto& NewMediaToCookEntry = MediaMap.Emplace(Id);
			NewMediaToCookEntry = MakeShared<MediaAssetToCook>();
			NewMediaToCookEntry->Id = Id;
			NewMediaToCookEntry->AssetPath = AssetPath;
			NewMediaToCookEntry->Language = Language;
			NewMediaToCookEntry->CachePath = CachePath;
			NewMediaToCookEntry->MediaName = MediaName;

			MediaAssetPerPlatformData& ParsedPlatformData = NewMediaToCookEntry->ParsedPerPlatformData.FindOrAdd(Platform);
			ParsedPlatformData.IsStreamed = bIsStreamed;
			ParsedPlatformData.PrefetchSize = 0;
			ParsedPlatformData.UseDeviceMemory = bUseDeviceMemory;
			ParsedPlatformData.Platform = Platform;
		}
	}

	return changed;
}

void AkSoundDataBuilder::ParseGameSyncs(const TSharedPtr<FJsonObject>& soundBankJson)
{
	if (!AkUnrealHelper::IsUsingEventBased())
	{
		return;
	}

	const TArray<TSharedPtr<FJsonValue>>* stateGroups = nullptr;
	if (soundBankJson->TryGetArrayField("StateGroups", stateGroups))
	{
		for (auto& stateGroupValueJson : *stateGroups)
		{
			auto& stateGroupJson = stateGroupValueJson->AsObject();

			FString stringGroupId = stateGroupJson->GetStringField("Id");
			uint32 groupId = static_cast<uint32>(FCString::Atoi64(*stringGroupId));

			auto& statesJson = stateGroupJson->GetArrayField("States");

			for (auto& stateValueJson : statesJson)
			{
				parseGroupValue(stateValueJson->AsObject(), groupId);
			}
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* switchGroups = nullptr;
	if (soundBankJson->TryGetArrayField("SwitchGroups", switchGroups))
	{
		for (auto& switchGroupValueJson : *switchGroups)
		{
			auto& switchGroupJson = switchGroupValueJson->AsObject();

			FString stringGroupId = switchGroupJson->GetStringField("Id");
			uint32 groupId = static_cast<uint32>(FCString::Atoi64(*stringGroupId));

			auto& switchesJson = switchGroupJson->GetArrayField("Switches");

			for (auto& switchValueJson : switchesJson)
			{
				parseGroupValue(switchValueJson->AsObject(), groupId);
			}
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* gameParameters = nullptr;
	if (soundBankJson->TryGetArrayField("GameParameters", gameParameters))
	{
		for (auto& gameParameterJsonValue : *gameParameters)
		{
			parseGameParameter(gameParameterJsonValue->AsObject());
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* triggers = nullptr;
	if (soundBankJson->TryGetArrayField("IncludedTriggers", triggers))
	{
		for (auto& triggerJsonValue : *triggers)
		{
			parseTrigger(triggerJsonValue->AsObject());
		}
	}
}

bool AkSoundDataBuilder::ParseBankHash(UAkAssetData* bankData, const TSharedPtr<FJsonObject>& soundBankJson)
{
	bool changed = false;

	FString stringHash;
	if (soundBankJson->TryGetStringField(TEXT("Hash"), stringHash))
	{
		auto newBankHash = static_cast<uint32>(FCString::Strtoui64(*stringHash, nullptr, 10));
		if (bankData->CachedHash != newBankHash)
		{
			bankData->CachedHash = newBankHash;
			changed = true;
		}
	}

	return changed;
}

void AkSoundDataBuilder::parseGroupValue(const TSharedPtr<FJsonObject>& groupValueObject, uint32 groupId)
{
	FString stringGuid = groupValueObject->GetStringField("GUID");

	FGuid guid;
	FGuid::ParseExact(stringGuid, EGuidFormats::DigitsWithHyphensInBraces, guid);

	if (auto groupValue = AkAssetDatabase::Get().GroupValueMap.FindLiveAsset(guid))
	{
		FString stringId = groupValueObject->GetStringField("Id");
		uint32 valueId = static_cast<uint32>(FCString::Atoi64(*stringId));

		bool changed = false;

		if (groupValue->GroupShortID != groupId)
		{
			groupValue->GroupShortID = groupId;
			changed = true;
		}

		if (groupValue->ShortID != valueId)
		{
			groupValue->ShortID = valueId;
			changed = true;
		}

		if (changed)
		{
			MarkAssetDirty(groupValue);
		}
	}
}

void AkSoundDataBuilder::parseGameParameter(const TSharedPtr<FJsonObject>& gameParameterObject)
{
	FString stringGuid = gameParameterObject->GetStringField("GUID");

	FGuid guid;
	FGuid::ParseExact(stringGuid, EGuidFormats::DigitsWithHyphensInBraces, guid);

	if (auto rtpc = AkAssetDatabase::Get().RtpcMap.FindLiveAsset(guid))
	{
		FString stringId = gameParameterObject->GetStringField("Id");
		uint32 valueId = static_cast<uint32>(FCString::Atoi64(*stringId));

		bool changed = false;

		if (rtpc->ShortID != valueId)
		{
			rtpc->ShortID = valueId;
			changed = true;
		}

		if (changed)
		{
			MarkAssetDirty(rtpc);
		}
	}
}

void AkSoundDataBuilder::parseTrigger(const TSharedPtr<FJsonObject>& triggerObject)
{
	FString stringGuid = triggerObject->GetStringField("GUID");

	FGuid guid;
	FGuid::ParseExact(stringGuid, EGuidFormats::DigitsWithHyphensInBraces, guid);

	if (auto trigger = AkAssetDatabase::Get().TriggerMap.FindLiveAsset(guid))
	{
		FString stringId = triggerObject->GetStringField("Id");
		uint32 valueId = static_cast<uint32>(FCString::Atoi64(*stringId));

		bool changed = false;

		if (trigger->ShortID != valueId)
		{
			trigger->ShortID = valueId;
			changed = true;
		}

		if (changed)
		{
			MarkAssetDirty(trigger);
		}
	}
}

bool AkSoundDataBuilder::ParseMedia(const TSharedPtr<FJsonObject>& soundBankJson, TMap<uint32, TSoftObjectPtr<UAkMediaAsset>>& NewMediaMap, const FString& platform)
{
	if (!AkUnrealHelper::IsUsingEventBased())
	{
		return false;
	}

	bool bChanged = false;

	const TArray<TSharedPtr<FJsonValue>>* streamedFiles = nullptr;
	if (soundBankJson->TryGetArrayField("ReferencedStreamedFiles", streamedFiles))
	{
		for (auto& streamJsonValue : *streamedFiles)
		{
			bChanged |= ProcessMediaEntry(platform, NewMediaMap, streamJsonValue->AsObject(), true);
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* excludedMemoryFiles = nullptr;
	if (soundBankJson->TryGetArrayField("ExcludedMemoryFiles", excludedMemoryFiles))
	{
		for (auto& mediaJsonValue : *excludedMemoryFiles)
		{
			bChanged |= ProcessMediaEntry(platform, NewMediaMap, mediaJsonValue->AsObject(), false);
		}
	}

	return bChanged;
}

bool AkSoundDataBuilder::MediaListsAreDifferent(const TArray<TSoftObjectPtr<UAkMediaAsset>>& OldList, const TArray<TSoftObjectPtr<UAkMediaAsset>>& NewList)
{
	if (OldList.Num() != NewList.Num())
	{
		return true;
	}

	for (int j = 0; j < OldList.Num(); j++)
	{
		TSoftObjectPtr<UAkMediaAsset> OldMediaItem = OldList[j];
		const TSoftObjectPtr<UAkMediaAsset>* NewMediaItem = NewList.FindByPredicate([OldMediaItem](const TSoftObjectPtr<UAkMediaAsset> ItemInArray) { return ItemInArray.GetUniqueID() == OldMediaItem.GetUniqueID(); });
		if (!NewMediaItem)
		{
			return true;
		}
	}

	return false;
}

bool AkSoundDataBuilder::DidSwitchContainerDataChange(const TArray<UAkAssetDataSwitchContainerData*>& OldData, const TArray<UAkAssetDataSwitchContainerData*>& NewData)
{
	if (OldData.Num() != NewData.Num())
	{
		return true;
	}

	for (int32 i = 0; i < OldData.Num(); i++)
	{
		// Find the appropriate Switch Container Data in the new array
		UAkAssetDataSwitchContainerData* OldItem = OldData[i];
		if (!OldItem)
		{
			return true;
		}

		UAkAssetDataSwitchContainerData* const* NewItem = NewData.FindByPredicate([OldItem](const UAkAssetDataSwitchContainerData* ItemInArray) { return ItemInArray->GroupValue.GetUniqueID() == OldItem->GroupValue.GetUniqueID(); });
		if (!NewItem || !(*NewItem))
		{
			return true;
		}

		if (!OldItem->DefaultGroupValue && (*NewItem)->DefaultGroupValue)
		{
			return true;
		}

		if (OldItem->DefaultGroupValue && (*NewItem)->DefaultGroupValue && OldItem->DefaultGroupValue->ID != (*NewItem)->DefaultGroupValue->ID)
		{
			return true;
		}

		if (MediaListsAreDifferent(OldItem->TempMediaList, (*NewItem)->TempMediaList))
		{
			return true;
		}

		if (DidSwitchContainerDataChange(OldItem->Children, (*NewItem)->Children))
		{
			return true;
		}
	}

	return false;
}

bool AkSoundDataBuilder::ParseMediaAndSwitchContainers(TSharedPtr<FJsonObject> EventJson, UAkAssetDataSwitchContainer* AssetData, const FString& Platform, const FString& Language)
{

	AssetData->FillTempMediaList();
	{
		FScopeLock AutoLock(&MediaLock);
		AllMediaData.Add(AssetData);
	}

	bool bChanged = false;
	TMap<uint32, TSoftObjectPtr<UAkMediaAsset>> ParsedEventMedia;

	ParseMedia(EventJson, ParsedEventMedia, Platform);

	if (SplitSwitchContainerMedia)
	{
		TArray<UAkAssetDataSwitchContainerData*> NewSwitchContainerData;
		const TArray<TSharedPtr<FJsonValue>>* SwitchContainers = nullptr;
		if (EventJson->TryGetArrayField("SwitchContainers", SwitchContainers))
		{
			for (auto& SwitchContainerValueJson : *SwitchContainers)
			{
				auto& SwitchContainerJson = SwitchContainerValueJson->AsObject();
				ParseSwitchContainer(SwitchContainerJson, NewSwitchContainerData, ParsedEventMedia, AssetData, Platform, Language);
			}
		}

		if (DidSwitchContainerDataChange(AssetData->SwitchContainers, NewSwitchContainerData))
		{
			AssetData->SwitchContainers.Empty();
			AssetData->SwitchContainers.Append(NewSwitchContainerData);
			bChanged = true;
		}
	}

	{
		FScopeLock AutoLock(&MediaLock);
		MediaToCookMap& CookMap = GetMediaToCookMap(Platform);
		MediaIdMap* LanguageMap = CookMap.Find(Language);
		MediaIdMap* SFXMap = CookMap.Find(TEXT("SFX"));
		if (!LanguageMap && ParsedEventMedia.Num()>0)
		{
			UE_LOG(LogAkAudio, Error, TEXT("Could not find media map for language %s while parsing switch containers"), *Language);
		}

		//AutoLoad is false by default
		//Being in a switch container (with SplitSwitchContainerMedia activated) will prune the asset from ParsedEventMedia
		//At this point we know that all the assets in the NewMediaList should be auto-loaded
		for (TPair<uint32, TSoftObjectPtr<UAkMediaAsset>> MediaPair : ParsedEventMedia)
		{
			bool bSuccess = false;
			TSharedPtr<MediaAssetToCook>* AssetToCook = LanguageMap ? LanguageMap->Find(MediaPair.Key) : nullptr;
			if (AssetToCook && AssetToCook->IsValid())
			{
				AssetToCook->Get()->AutoLoad = true;
				bSuccess = true;
			}

			if(!bSuccess && SFXMap)
			{
				// The media might be related to a plugin, and would be in the SFX map in that case.
				AssetToCook = SFXMap->Find(MediaPair.Key);
				if (AssetToCook && AssetToCook->IsValid())
				{
					AssetToCook->Get()->AutoLoad = true;
					bSuccess = true;
				}
			}

			if (!bSuccess)
			{
				UE_LOG(LogAkAudio, Error, TEXT("Could not set autoload to true for media %s"), *MediaPair.Value.ToSoftObjectPath().ToString());
			}
		}
	}

	UAkGroupValue* newDefaultSwitchValue = nullptr;

	FString stringDefaultSwitchValue;
	if (EventJson->TryGetStringField("DefaultSwitchValue", stringDefaultSwitchValue))
	{
		FGuid defaultSwitchValueID;
		FGuid::ParseExact(stringDefaultSwitchValue, EGuidFormats::DigitsWithHyphensInBraces, defaultSwitchValueID);

		if (auto foundDefaultSwitchValue = AkAssetDatabase::Get().GroupValueMap.FindLiveAsset(defaultSwitchValueID))
		{
			newDefaultSwitchValue = foundDefaultSwitchValue;
		}
	}

	if ((!AssetData->DefaultGroupValue && newDefaultSwitchValue)
		|| (AssetData->DefaultGroupValue && newDefaultSwitchValue && AssetData->DefaultGroupValue->ID != newDefaultSwitchValue->ID)
		)
	{
		AssetData->DefaultGroupValue = newDefaultSwitchValue;
		bChanged = true;
	}

	TArray< TSoftObjectPtr<UAkMediaAsset>> NewMediaList;
	ParsedEventMedia.GenerateValueArray(NewMediaList);
	if (MediaListsAreDifferent(AssetData->TempMediaList, NewMediaList))
	{
		AssetData->TempMediaList.Empty();
		AssetData->TempMediaList.Append(NewMediaList);
		bChanged = true;
	}

	return bChanged;
}

template<typename AssetType>
bool AkSoundDataBuilder::ParseEventMetadataSection(TSharedPtr<FJsonObject> eventJson, const FString& SectionName, const AkAssetDatabase::AkTypeMap<AssetType>* AssetMap, TSet<AssetType*>* DestinationSet)
{
	bool changed = false;

	const TArray<TSharedPtr<FJsonValue>>* Actions = nullptr;
	if (eventJson->TryGetArrayField(SectionName, Actions))
	{
		for (auto& ValueJson : *Actions)
		{
			auto& JsonObject = ValueJson->AsObject();
			FGuid AssetGuid;
			FString AssetGuidString = JsonObject->GetStringField("GUID");
			FGuid::ParseExact(AssetGuidString, EGuidFormats::DigitsWithHyphensInBraces, AssetGuid);

			if (auto asset = AssetMap->FindLiveAsset(AssetGuid))
			{
				bool WasAlreadyThere = false;
				DestinationSet->Add(asset, &WasAlreadyThere);
				changed |= !WasAlreadyThere;
			}
		}
	}

	return changed;
}

bool AkSoundDataBuilder::ParseEventAssetInfo(UAkAudioEvent* AkEvent, UAkAssetData* PlatformData, const FString& Platform, const FString& Language, const TSharedPtr<FJsonObject>& SoundBankJson)
{
	bool bChanged = false;
	if (auto* EventPlatformData = Cast<UAkAudioEventData>(PlatformData))
	{
		if (EventPlatformData->BankLanguage != Language)
		{
			EventPlatformData->BankLanguage = Language;
			bChanged = true;
		}

		const TArray<TSharedPtr<FJsonValue>>* EventsArray = nullptr;
		if (SoundBankJson->TryGetArrayField("IncludedEvents", EventsArray))
		{
			for (auto& EventJsonValue : *EventsArray)
			{
				auto& EventJson = EventJsonValue->AsObject();
				FString EventStringId = EventJson->GetStringField("GUID");

				FGuid EventId;
				FGuid::ParseExact(EventStringId, EGuidFormats::DigitsWithHyphensInBraces, EventId);

				if (EventId == AkEvent->ID)
				{
					bChanged |= ParseEventInfo(AkEvent, EventPlatformData, EventJson);
					bChanged |= ParseMediaAndSwitchContainers(EventJson, EventPlatformData, Platform, Language);
					bChanged |= ParseEventMetadataSection(EventJson, FString(TEXT("ActionPostEvent")), &AkAssetDatabase::Get().EventMap, &EventPlatformData->PostedEvents);
					bChanged |= ParseEventMetadataSection(EventJson, FString(TEXT("AuxBusSends")), &AkAssetDatabase::Get().AuxBusMap, &EventPlatformData->UserDefinedSends);
					bChanged |= ParseEventMetadataSection(EventJson, FString(TEXT("ActionTrigger")), &AkAssetDatabase::Get().TriggerMap, &EventPlatformData->PostedTriggers);
					bChanged |= ParseEventMetadataSection(EventJson, FString(TEXT("ActionSetSwitch")), &AkAssetDatabase::Get().GroupValueMap, &EventPlatformData->GroupValues);
					bChanged |= ParseEventMetadataSection(EventJson, FString(TEXT("ActionSetState")), &AkAssetDatabase::Get().GroupValueMap, &EventPlatformData->GroupValues);

					if (EventPlatformData->AssetPlatform != Platform)
					{
						EventPlatformData->AssetPlatform = Platform;
						bChanged = true;
					}

					break;
				}
			}
		}
	}

	return bChanged;
}

bool AkSoundDataBuilder::ParseEventInfo(UAkAudioEvent* akEvent, UAkAudioEventData* eventPlatformData, const TSharedPtr<FJsonObject>& eventJson)
{
	bool changed = false;

	FString stringId;
	if (eventJson->TryGetStringField("Id", stringId))
	{
		uint32 id = static_cast<uint32>(FCString::Atoi64(*stringId));
		if (akEvent->ShortID != id)
		{
			akEvent->ShortID = id;
			changed = true;
		}
	}

	FString ValueString;
	if (eventJson->TryGetStringField("MaxAttenuation", ValueString))
	{
		const float EventRadius = FCString::Atof(*ValueString);
		if (eventPlatformData->MaxAttenuationRadius != EventRadius)
		{
			eventPlatformData->MaxAttenuationRadius = EventRadius;
			changed = true;
		}
	}
	else
	{
		if (eventPlatformData->MaxAttenuationRadius != 0)
		{
			// No attenuation info in json file, set to 0.
			eventPlatformData->MaxAttenuationRadius = 0;
			changed = true;
		}
	}

	// if we can't find "DurationType", then we assume infinite
	const bool IsInfinite = !eventJson->TryGetStringField("DurationType", ValueString) || (ValueString == "Infinite") || (ValueString == "Unknown");
	if (eventPlatformData->IsInfinite != IsInfinite)
	{
		eventPlatformData->IsInfinite = IsInfinite;
		changed = true;
	}

	if (!IsInfinite)
	{
		if (eventJson->TryGetStringField("DurationMin", ValueString))
		{
			const float DurationMin = FCString::Atof(*ValueString);
			if (eventPlatformData->MinimumDuration != DurationMin)
			{
				eventPlatformData->MinimumDuration = DurationMin;
				changed = true;
			}
		}

		if (eventJson->TryGetStringField("DurationMax", ValueString))
		{
			const float DurationMax = FCString::Atof(*ValueString);
			if (eventPlatformData->MaximumDuration != DurationMax)
			{
				eventPlatformData->MaximumDuration = DurationMax;
				changed = true;
			}
		}
	}

	return changed;
}

void AkSoundDataBuilder::ParseSwitchContainer(const TSharedPtr<FJsonObject>& SwitchContainerJson, TArray<UAkAssetDataSwitchContainerData*>& InOutSwitchContainerData, TMap<uint32, TSoftObjectPtr<UAkMediaAsset>>& InOutEventMedia, UObject* Parent, const FString& Platform, const FString& Language)
{
	FString stringSwitchValue = SwitchContainerJson->GetStringField("SwitchValue");
	FGuid switchValueGuid;
	FGuid::ParseExact(stringSwitchValue, EGuidFormats::DigitsWithHyphensInBraces, switchValueGuid);

	UAkAssetDataSwitchContainerData* SwitchContainerEntry;
	auto groupValue = AkAssetDatabase::Get().GroupValueMap.FindLiveAsset(switchValueGuid);
	if (groupValue)
	{
		UAkAssetDataSwitchContainerData** SwitchContainerEntryPtr = InOutSwitchContainerData.FindByPredicate([=](UAkAssetDataSwitchContainerData* ItemInArray) { return ItemInArray->GroupValue.GetAssetName() == groupValue->GetName(); });
		if (SwitchContainerEntryPtr == nullptr)
		{
			SwitchContainerEntry = NewObject<UAkAssetDataSwitchContainerData>(Parent);
		}
		else
		{
			SwitchContainerEntry = *SwitchContainerEntryPtr;
		}
		SwitchContainerEntry->GroupValue = groupValue;
	}
	else
	{
		SwitchContainerEntry = NewObject<UAkAssetDataSwitchContainerData>(Parent);
	}

	FString stringDefaultSwitchValue;
	if (SwitchContainerJson->TryGetStringField("DefaultSwitchValue", stringDefaultSwitchValue))
	{
		FGuid defaultSwitchValue;
		FGuid::ParseExact(stringDefaultSwitchValue, EGuidFormats::DigitsWithHyphensInBraces, defaultSwitchValue);

		if (auto defaultGroupValue = AkAssetDatabase::Get().GroupValueMap.FindLiveAsset(defaultSwitchValue))
		{
			SwitchContainerEntry->DefaultGroupValue = defaultGroupValue;
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* JsonMediaList = nullptr;
	if (SwitchContainerJson->TryGetArrayField("Media", JsonMediaList))
	{
		MediaDependencySet MediaDependenciesInJson;
		for (auto& MediaJsonValue : *JsonMediaList)
		{
			auto& MediaJsonObject = MediaJsonValue->AsObject();

			FString StringId = MediaJsonObject->GetStringField("Id");
			uint32 MediaFileId = static_cast<uint32>(FCString::Atoi64(*StringId));

			FSoftObjectPath* MediaAssetPath = nullptr;
			{
				FScopeLock AutoLock(&MediaLock);
				MediaToCookMap& CookMap = GetMediaToCookMap(Platform);

				if (MediaIdMap* MediaMap = CookMap.Find(Language))
				{

					if (TSharedPtr<MediaAssetToCook>* MediaAssetToCook = MediaMap->Find(MediaFileId))
					{
						if (MediaAssetToCook->IsValid())
						{
							MediaAssetPath = &MediaAssetToCook->Get()->AssetPath;

						}
					}
				}

				if (MediaAssetPath)
				{
					SwitchContainerEntry->TempMediaList.Emplace(*MediaAssetPath);

					InOutEventMedia.Remove(MediaFileId);

					MediaDependenciesInJson.Add(TSoftObjectPtr<UAkMediaAsset>(*MediaAssetPath));
				}
				else
				{
					UE_LOG(LogAkAudio, Warning, TEXT("Media with id %u listed in switch container was not parsed beforehand. It will not be added to the container."), MediaFileId);
				}
			}
		}

		{
			FScopeLock AutoLock(&MediaDependenciesLock);
			if (groupValue)
			{
				TempMediaDependenciesList.FindOrAdd(groupValue).Append(MediaDependenciesInJson);
			}
			else
			{
				UE_LOG(LogAkAudio, Log, TEXT("Couldn't find group value asset with GUID %s, likely due to a generic path being used in a music switch container.\n The media in switch container %s will be set to AutoLoad with events that reference it."), *stringSwitchValue, *SwitchContainerEntry->GetFullName());
				MediaAssetsInSwitchContainersMissingGroupValues.Append(MediaDependenciesInJson);
			}
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* children = nullptr;
	if (SwitchContainerJson->TryGetArrayField("Children", children))
	{
		for (auto& childJsonValue : *children)
		{
			auto& childJsonObject = childJsonValue->AsObject();

			ParseSwitchContainer(childJsonObject, SwitchContainerEntry->Children, InOutEventMedia, Parent, Platform, Language);
		}
	}

	InOutSwitchContainerData.AddUnique(SwitchContainerEntry);
}

bool AkSoundDataBuilder::ParseSoundBankInfo(UAkAssetBase* MainAsset, UAkAssetData* PlatformAsset, const FString& Platform, const FString& Language, const TSharedPtr<FJsonObject>& SoundBankJson)
{
	bool bChanged = false;
	if (auto AudioEventAsset = Cast<UAkAudioEvent>(MainAsset))
	{
		bChanged |= ParseEventAssetInfo(AudioEventAsset, PlatformAsset, Platform, Language, SoundBankJson);
	}
	else if (auto AuxBusAsset = Cast<UAkAuxBus>(MainAsset))
	{
		bChanged |= ParseAuxBusAssetInfo(AuxBusAsset, PlatformAsset, Platform, Language, SoundBankJson);
	}
	else if (auto AudioBankAsset = Cast<UAkAudioBank>(MainAsset))
	{
		bChanged |= ParseAudioBankAssetInfo(AudioBankAsset, Platform, Language, SoundBankJson);
	}
	else if (auto InitBankAsset = Cast<UAkInitBank>(MainAsset))
	{
		// Parse aux bus media
		if (auto* MediaPlatformData = Cast<UAkAssetDataWithMedia>(PlatformAsset))
		{
			//Fill temp media list with current serialized media
			MediaPlatformData->FillTempMediaList();

			TMap<uint32, TSoftObjectPtr<UAkMediaAsset>> ParsedMediaMap;
			TArray<TSoftObjectPtr<UAkMediaAsset>> TempParsedMedia;
			ParseMedia(SoundBankJson, ParsedMediaMap, Platform);
			ParsedMediaMap.GenerateValueArray(TempParsedMedia);

			if (MediaListsAreDifferent(MediaPlatformData->TempMediaList, TempParsedMedia))
			{
				MediaPlatformData->TempMediaList.Empty();
				MediaPlatformData->TempMediaList.Append(TempParsedMedia);
				bChanged = true;
			}

			{
				FScopeLock AutoLock(&MediaLock);
				AllMediaData.Add(MediaPlatformData);
				MediaToCookMap& CookMap = GetMediaToCookMap(Platform);
				MediaIdMap* LanguageMap = CookMap.Find(Language);
				if (!LanguageMap && ParsedMediaMap.Num() >0)
				{
					UE_LOG(LogAkAudio, Error, TEXT("Could not find media map for language %s when parsing media in Init Bank"), *Language);
				}
				else
				{
					//Aux bus media (effect media) should have AutoLoad set to true
					for (TPair<uint32, TSoftObjectPtr<UAkMediaAsset>> MediaPair : ParsedMediaMap)
					{
						bool bSuccess = false;
						if (TSharedPtr<MediaAssetToCook>* AssetToCook = LanguageMap->Find(MediaPair.Key))
						{
							if (AssetToCook->IsValid())
							{
								AssetToCook->Get()->AutoLoad = true;
								bSuccess = true;
							}
						}
						if (!bSuccess)
						{
							UE_LOG(LogAkAudio, Error, TEXT("Could not set autoload to true for media %s"), *MediaPair.Value.ToSoftObjectPath().ToString());
						}
					}
				}				
			}
		}

		bChanged |= ParseInitBankAssetInfo(InitBankAsset, SoundBankJson);
	}

	ParseGameSyncs(SoundBankJson);
	if (AkUnrealHelper::IsUsingEventBased())
	{
		bChanged |= ParseBankHash(PlatformAsset, SoundBankJson);
	}
	return bChanged;
}

bool AkSoundDataBuilder::ParseAuxBusAssetInfo(UAkAuxBus* AkAuxBus, UAkAssetData* AuxBusPlatformData, const FString& Platform, const FString& Language, const TSharedPtr<FJsonObject>& SoundBankJson)
{
	bool bChanged = false;

	const TArray<TSharedPtr<FJsonValue>>* AuxBusses = nullptr;
	if (SoundBankJson->TryGetArrayField("IncludedAuxBusses", AuxBusses))
	{
		for (auto& AuxBusJsonValue : *AuxBusses)
		{
			auto& AuxBusJson = AuxBusJsonValue->AsObject();
			FString AuxBusStringId = AuxBusJson->GetStringField("GUID");

			FGuid AuxBusId;
			FGuid::ParseExact(AuxBusStringId, EGuidFormats::DigitsWithHyphensInBraces, AuxBusId);

			if (AuxBusId == AkAuxBus->ID)
			{
				FString StringId;
				if (AuxBusJson->TryGetStringField("Id", StringId))
				{
					uint32 Id = static_cast<uint32>(FCString::Atoi64(*StringId));
					if (AkAuxBus->ShortID != Id)
					{
						AkAuxBus->ShortID = Id;
						bChanged = true;
					}
				}
				break;
			}
		}
	}

	return bChanged;
}

bool AkSoundDataBuilder::GetAuxBusFromBankInfo(const TSharedPtr<FJsonObject>& SoundBankJson)
{
	auto& akAssetDatabase = AkAssetDatabase::Get();
	bool bChanged = false;
	const TArray<TSharedPtr<FJsonValue>>* auxBusses = nullptr;
	if (SoundBankJson->TryGetArrayField("IncludedAuxBusses", auxBusses))
	{
		for (auto& auxBusJsonValue : *auxBusses)
		{
			auto& auxBusJson = auxBusJsonValue->AsObject();
			FString auxBusStringId;
			FGuid auxBusId;

			if (auxBusJson->TryGetStringField("GUID", auxBusStringId) && !auxBusStringId.IsEmpty())
			{
				FGuid::ParseExact(auxBusStringId, EGuidFormats::DigitsWithHyphensInBraces, auxBusId);
			}

			FAssetData auxBusByName;
			const FAssetData* akAuxBusIt = nullptr;

			akAuxBusIt = akAssetDatabase.AuxBusMap.Find(auxBusId);
			if (!akAuxBusIt)
			{
				auto foundAuxBusses = akAssetDatabase.AuxBusMap.FindByName(auxBusJson->GetStringField("Name"));
				if (foundAuxBusses.Num() > 0)
				{
					auxBusByName = foundAuxBusses[0];
					akAuxBusIt = &auxBusByName;
				}
			}

			if (akAuxBusIt)
			{
				if (auto akAuxBus = Cast<UAkAuxBus>(akAuxBusIt->GetAsset()))
				{
					FString stringId;
					if (auxBusJson->TryGetStringField("Id", stringId))
					{
						uint32 id = static_cast<uint32>(FCString::Atoi64(*stringId));
						if (akAuxBus->ShortID != id)
						{
							akAuxBus->ShortID = id;
							MarkAssetDirty(akAuxBus);
							bChanged = true;
						}
					}
				}
			}
		}
	}

	return bChanged;

}

bool AkSoundDataBuilder::ParseInitBankAssetInfo(UAkInitBank* AkInitBank, const TSharedPtr<FJsonObject>& SoundBankJson)
{
	AkInitBank->DefaultLanguage = DefaultLanguage;
	return GetAuxBusFromBankInfo(SoundBankJson);
}

bool AkSoundDataBuilder::ParseAudioBankAssetInfo(UAkAudioBank* AkAudioBank, const FString& Platform, const FString& Language, const TSharedPtr<FJsonObject>& SoundBankJson)
{
	auto& AkAssetDatabase = AkAssetDatabase::Get();

	const TArray<TSharedPtr<FJsonValue>>* EventsArray = nullptr;
	if (SoundBankJson->TryGetArrayField("IncludedEvents", EventsArray))
	{
		for (TSharedPtr<FJsonValue> EventJsonValue : *EventsArray)
		{
			auto& EventJson = EventJsonValue->AsObject();

			FString EventStringId;
			FGuid EventId;
			if (EventJson->TryGetStringField("GUID", EventStringId) && !EventStringId.IsEmpty())
			{
				FGuid::ParseExact(EventStringId, EGuidFormats::DigitsWithHyphensInBraces, EventId);
			}

			FAssetData EventByName;
			const FAssetData* EventIt = AkAssetDatabase.EventMap.Find(EventId);
			if (!EventIt)
			{
				auto FoundEvents = AkAssetDatabase.EventMap.FindByName(EventJson->GetStringField("Name"));
				if (FoundEvents.Num() > 0)
				{
					EventByName = FoundEvents[0];
					EventIt = &EventByName;
				}
			}

			if (EventIt)
			{
				struct EventRequiredData
				{
					UAkAudioEvent* AkAudioEvent = nullptr;
					UAkAssetData* EventPlatformData = nullptr;
				};

				TSharedPtr<EventRequiredData> RequiredData = MakeShared<EventRequiredData>();
				RequiredData->AkAudioEvent = Cast<UAkAudioEvent>(EventIt->GetAsset());
				{
					FScopeLock AutoLock(&ParseTasksLock);
					FGraphEventRef FetchPlatformDataTask = FFunctionGraphTask::CreateAndDispatchWhenReady(
						[sharedThis = SharedThis(this), RequiredData, Platform, Language, EventJson]()
					{
						if (RequiredData->AkAudioEvent)
						{
							RequiredData->EventPlatformData = RequiredData->AkAudioEvent->FindOrAddAssetData(Platform, Language);
						}
						if (RequiredData->AkAudioEvent && RequiredData->EventPlatformData)
						{
							bool bChanged = false;

							UAkAudioEventData* EventData = Cast<UAkAudioEventData>(RequiredData->EventPlatformData);
							bChanged |= sharedThis->ParseEventInfo(RequiredData->AkAudioEvent, EventData, EventJson);

							if (EventData->AssetPlatform != Platform)
							{
								EventData->AssetPlatform = Platform;
								bChanged = true;
							}
							if (AkUnrealHelper::IsUsingEventBased())
							{
								if (auto* EventPlatformData = Cast<UAkAudioEventData>(RequiredData->EventPlatformData))
								{
									bChanged |= sharedThis->ParseMediaAndSwitchContainers(EventJson, EventPlatformData, Platform, Language);
								}
							}
							if (bChanged)
							{
								sharedThis->MarkAssetDirty(RequiredData->AkAudioEvent);
								sharedThis->MarkAssetDirty(RequiredData->EventPlatformData);
							}
						}

					}, GET_STATID(STAT_EventPlatformDataEventGroup), nullptr, ENamedThreads::GameThread);

					PostParseTasks.Add(FetchPlatformDataTask);
				}
			}
		}
	}

	GetAuxBusFromBankInfo(SoundBankJson);

	return false;
}

bool AkSoundDataBuilder::parsePluginInfo(UAkInitBank* InitBank, const FString& Platform, const TSharedPtr<FJsonObject>& PluginInfoJson)
{
	auto& pluginsArrayJson = PluginInfoJson->GetArrayField(TEXT("Plugins"));

	auto platformData = InitBank->FindOrAddAssetDataTyped<UAkInitBankAssetData>(Platform, TEXT("SFX"));
	if (!platformData)
	{
		return false;
	}

	TArray<FAkPluginInfo> NewPluginInfo;
	for (auto& pluginJsonValue : pluginsArrayJson)
	{
		auto& pluginJson = pluginJsonValue->AsObject();

		FString pluginDLL;
		bool HasDLL = pluginJson->TryGetStringField(TEXT("DLL"), pluginDLL);
		if (!HasDLL || pluginDLL == TEXT("DefaultSink") || pluginDLL == TEXT("AkSoundEngineDLL"))
		{
			continue;
		}

		auto pluginName = pluginJson->GetStringField(TEXT("Name"));
		auto pluginStringID = pluginJson->GetStringField(TEXT("ID"));

		auto pluginID = static_cast<uint32>(FCString::Atoi64(*pluginStringID));

		NewPluginInfo.Emplace(pluginName, pluginID, pluginDLL);
	}

	bool changed = false;
	if (platformData->PluginInfos.Num() != NewPluginInfo.Num())
	{
		changed = true;
	}
	else
	{
		for (int i = 0; i < platformData->PluginInfos.Num(); i++)
		{
			FAkPluginInfo OldPluginInfo = platformData->PluginInfos[i];
			if (!NewPluginInfo.ContainsByPredicate([OldPluginInfo](const FAkPluginInfo& ItemInArray) { return ItemInArray.PluginID == OldPluginInfo.PluginID; }))
			{
				changed = true;
				break;
			}
		}
	}

	if (changed)
	{
		platformData->PluginInfos.Empty();
		platformData->PluginInfos.Append(NewPluginInfo);
	}

	if (changed && platformData->PluginInfos.Num() > 0)
	{
		StaticPluginWriter::OutputPluginInformation(InitBank, Platform);
	}

	return changed;
}

void AkSoundDataBuilder::CookMediaAsset(MediaAssetToCook& MediaToCook, const FString& Platform)
{
	if (!MediaToCook.Instance || !MediaToCook.CurrentPlatformData)
	{
		return;
	}

	bool bChanged = false;
	UAkMediaAsset* MediaAsset = MediaToCook.Instance;

	if (MediaAsset->Id != MediaToCook.Id)
	{
		MediaAsset->Id = MediaToCook.Id;
		bChanged = true;
	}

	if (MediaAsset->MediaName != MediaToCook.MediaName)
	{
		MediaAsset->MediaName = MediaToCook.MediaName;
		bChanged = true;
	}

	if (MediaAsset->AutoLoad != MediaToCook.AutoLoad)
	{
		MediaAsset->AutoLoad = MediaToCook.AutoLoad;
		bChanged = true;
	}

	if (MediaAsset->Language != MediaToCook.Language)
	{
		MediaAsset->Language = MediaToCook.Language;
		bChanged = true;
	}

	auto MediaFilePath = FPaths::Combine(CacheDirectory, Platform, MediaToCook.CachePath);
	auto ModificationTime = platformFile->GetTimeStamp(*MediaFilePath).ToUnixTimestamp();
	auto PlatformData = MediaToCook.CurrentPlatformData;
	const MediaAssetPerPlatformData* ParsedPlatformData = MediaToCook.ParsedPerPlatformData.Find(Platform);
	if (!ParsedPlatformData)
	{
		return;
	}

	bool bIsStreamedDifferent = PlatformData->IsStreamed != ParsedPlatformData->IsStreamed;
	bool bPrefetchSizeDifferent = PlatformData->IsStreamed && PlatformData->DataChunks.Num() > 0 && PlatformData->DataChunks[0].IsPrefetch && PlatformData->DataChunks[0].Data.GetBulkDataSize() != ParsedPlatformData->PrefetchSize;


	if (bIsStreamedDifferent)
	{
		PlatformData->IsStreamed = ParsedPlatformData->IsStreamed;
		bChanged = true;
	}

	if (PlatformData->UseDeviceMemory != ParsedPlatformData->UseDeviceMemory)
	{
		PlatformData->UseDeviceMemory = ParsedPlatformData->UseDeviceMemory;
		bChanged = true;
	}

	if (PlatformData->AssetPlatform != ParsedPlatformData->Platform)
	{
		PlatformData->AssetPlatform = ParsedPlatformData->Platform;
		bChanged = true;
	}

	if (MediaAsset->Language != PlatformData->Language)
	{
		PlatformData->Language = MediaAsset->Language;
		bChanged = true;
	}

	bool BulkDataTypeIsOutOfDate = false;
	{
		FScopeLock autoLock(&PlatformData->DataLock);
		for (auto& DataChunk : PlatformData->DataChunks)
		{
			if ((DataChunk.Data.GetBulkDataFlags() & BULKDATA_ForceInlinePayload) != 0)
			{
				BulkDataTypeIsOutOfDate = true;
				break;
			}
		}
	}

	TUniquePtr<IFileHandle> FileReader(platformFile->OpenRead(*MediaFilePath));
	if (FileReader)
	{
		auto fileSize = FileReader->Size();

		TArray<uint8> TempData;
		TempData.Reserve(fileSize);

		FileReader->Read(TempData.GetData(), fileSize);

		auto NewHash = CityHash64(reinterpret_cast<const char*>(TempData.GetData()), fileSize);

		if (PlatformData->MediaContentHash != NewHash || bIsStreamedDifferent || bPrefetchSizeDifferent || BulkDataTypeIsOutOfDate)
		{
			{
				FScopeLock autoLock(&PlatformData->DataLock);
				PlatformData->DataChunks.Empty();
			}

			FileReader->Seek(0);

			if (ParsedPlatformData->IsStreamed && ParsedPlatformData->PrefetchSize > 0)
			{
				auto PrefetchChunk = new FAkMediaDataChunk(FileReader.Get(), ParsedPlatformData->PrefetchSize, BULKDATA_Force_NOT_InlinePayload, &MediaAsset->BulkDataWriteLock, true);
				{
					FScopeLock AutoLock(&PlatformData->DataLock);
					PlatformData->DataChunks.Add(PrefetchChunk);
				}
			}

			FileReader->Seek(0);
			auto DataChunk = new FAkMediaDataChunk(FileReader.Get(), fileSize, BULKDATA_Force_NOT_InlinePayload, &MediaAsset->BulkDataWriteLock);
			{
				FScopeLock autoLock(&PlatformData->DataLock);
				PlatformData->DataChunks.Add(DataChunk);
			}

			PlatformData->MediaContentHash = NewHash;

			bChanged = true;
		}
	}

	if (bChanged)
	{
		MarkAssetDirty(MediaAsset);
	}
}

void AkSoundDataBuilder::DispatchAndWaitMediaCookTasks()
{
	check(!bParsingMediaMap);
	bParsingMediaMap = true;
	for (auto& Entry : MediaToCookPerPlatform)
	{
		DispatchMediaCookTask(Entry.Value, Entry.Key);
	}

	FTaskGraphInterface::Get().WaitUntilTasksComplete(AllMediaTasks);
	bParsingMediaMap = false;

	FGraphEventArray MediaPathToMediaAssetTasks;

	for (auto& MediaPlatformData : AllMediaData)
	{
		MediaPathToMediaAssetTasks.Add(FFunctionGraphTask::CreateAndDispatchWhenReady([MediaPlatformData]
		{
			MediaPlatformData->FillFinalMediaList();
		}, GET_STATID(STAT_GatherMediaAssets), nullptr, ENamedThreads::GameThread));
	}

	{
		FScopeLock AutoLock(&MediaDependenciesLock);
		for (auto Pair : TempMediaDependenciesList)
		{
			UAkGroupValue* GroupValue = Pair.Key;
			MediaDependencySet& MediaDependenciesInJson = Pair.Value;
			MediaDependencySet MediaDependenciesInAsset(GroupValue->MediaDependencies);
			if (MediaDependenciesInJson.Num() != MediaDependenciesInAsset.Num() || !MediaDependenciesInJson.Includes(MediaDependenciesInAsset))
			{
				GroupValue->MediaDependencies.Reset();
				GroupValue->MediaDependencies.Append(MediaDependenciesInJson.Array());
				MarkAssetDirty(GroupValue);
			}

		}

		//Media assets with no group value (e.g. music on the generic path)
		for (auto MediaAsset : MediaAssetsInSwitchContainersMissingGroupValues)
		{
			if (UAkMediaAsset* Asset = MediaAsset.Get())
			{
				//Only do this for non-localized sounds
				if (Asset->Language == "SFX")
				{
					if (!Asset->AutoLoad)
					{
						Asset->AutoLoad = true;
						MarkAssetDirty(Asset);
					}
				}
			}
		}
	}

	FTaskGraphInterface::Get().WaitUntilTasksComplete(MediaPathToMediaAssetTasks);
}

void AkSoundDataBuilder::DispatchMediaCookTask(const MediaToCookMap& MediaMap, const FString& Platform)
{
	for (TPair<FString, MediaIdMap> LanguageEntry : MediaMap)
	{
		for (auto& MediaEntry : LanguageEntry.Value)
		{
			auto& MediaToCook = MediaEntry.Value;

			auto sharedThis = SharedThis(this);

			auto FetchMediaTask = FFunctionGraphTask::CreateAndDispatchWhenReady([sharedThis, MediaToCook, Platform] {
				UClass* MediaAssetClass = MediaToCook->Language == "SFX" ? UAkMediaAsset::StaticClass() : UAkLocalizedMediaAsset::StaticClass();

				FString AssetPackagePath = FPaths::GetPath(MediaToCook->AssetPath.GetAssetPathName().ToString());

				auto AssetData = sharedThis->AssetRegistryModule->Get().GetAssetByObjectPath(MediaToCook->AssetPath.GetAssetPathName());

				if (AssetData.IsValid())
				{
					MediaToCook->Instance = Cast<UAkMediaAsset>(AssetData.GetAsset());
				}
				else
				{
					MediaToCook->Instance = Cast<UAkMediaAsset>(sharedThis->AssetToolsModule->Get().CreateAsset(MediaToCook->AssetPath.GetAssetName(), AssetPackagePath, MediaAssetClass, nullptr));
				}

				if (MediaToCook->Instance)
				{
					MediaToCook->CurrentPlatformData = MediaToCook->Instance->FindOrAddMediaAssetData(Platform);
				}
			}, GET_STATID(STAT_GatherMediaAssets), nullptr, ENamedThreads::GameThread);

			{
				FScopeLock AutoLock(&MediaLock);
				AllMediaTasks.Add(FFunctionGraphTask::CreateAndDispatchWhenReady([sharedThis, MediaToCook, Platform]
				{
					sharedThis->CookMediaAsset(*MediaToCook.Get(), Platform);
				}, GET_STATID(STAT_CookMediaAsset), FetchMediaTask));
			}
		}
	}
}

void AkSoundDataBuilder::MarkAssetDirty(UObject* Obj)
{
	AsyncTask(ENamedThreads::GameThread, [Obj, sharedThis = SharedThis(this)]
		{
			if (!Obj->GetOutermost()->IsDirty())
			{
				Obj->GetOutermost()->MarkPackageDirty();
			}
			sharedThis->PackagesToSave.Add(Obj->GetOutermost());
		});
}

FString AkSoundDataBuilder::fillAudioBankInfoMap(AudioBankInfoMap& AudioBankInfoMap, FillAudioBankInfoKind InfoKind, const TSet<FString>& PlatformsToBuild, const TSet<FString>& LanguagesToBuild, ISoundBankInfoCache* SoundBankInfoCache)
{
	auto& akAssetDatabase = AkAssetDatabase::Get();
	TSet<FString> BanksToGenerate;

	{
		FScopeLock autoLock(&akAssetDatabase.EventMap.CriticalSection);

		for (auto& eventEntry : akAssetDatabase.EventMap.TypeMap)
		{
			if (auto eventInstance = Cast<UAkAudioEvent>(eventEntry.Value.GetAsset()))
			{
				if (eventInstance->RequiredBank)
				{
					if (!initParameters.SkipLanguages || (initParameters.SkipLanguages && eventInstance->RequiredBank->LocalizedPlatformAssetDataMap.Num() == 0))
					{
						FString audioBankName;
						if (AkToolBehavior::Get()->AkSoundDataBuilder_GetBankName(this, eventInstance->RequiredBank, initParameters.BanksToGenerate, audioBankName))
						{
							BanksToGenerate.Add(audioBankName);
						}

						if (initParameters.BanksToGenerate.Num() == 0 || initParameters.BanksToGenerate.Contains(audioBankName))
						{
							auto& infoEntry = AudioBankInfoMap.FindOrAdd(audioBankName);
							infoEntry.NeedsRebuild = infoEntry.NeedsRebuild || eventInstance->NeedsRebuild(PlatformsToBuild, LanguagesToBuild, SoundBankInfoCache);

							auto& eventSet = infoEntry.Events;
							switch (InfoKind)
							{
							case FillAudioBankInfoKind::GUID:
								eventSet.Add(eventInstance->ID.ToString(EGuidFormats::DigitsWithHyphensInBraces));
								break;
							case FillAudioBankInfoKind::AssetName:
								eventSet.Add(eventInstance->GetName());
								break;
							default:
								break;
							}
						}
					}
				}
			}
		}
	}

	{
		FScopeLock autoLock(&akAssetDatabase.AuxBusMap.CriticalSection);

		for (auto& auxBusEntry : akAssetDatabase.AuxBusMap.TypeMap)
		{
			if (auto auxBusInstance = Cast<UAkAuxBus>(auxBusEntry.Value.GetAsset()))
			{
				if (auxBusInstance->RequiredBank)
				{
					FString audioBankName;

					if (AkToolBehavior::Get()->AkSoundDataBuilder_GetBankName(this, auxBusInstance->RequiredBank, initParameters.BanksToGenerate, audioBankName))
					{
						BanksToGenerate.Add(audioBankName);
					}

					if (initParameters.BanksToGenerate.Num() == 0 || initParameters.BanksToGenerate.Contains(audioBankName))
					{
						auto& infoEntry = AudioBankInfoMap.FindOrAdd(audioBankName);
						infoEntry.NeedsRebuild = infoEntry.NeedsRebuild || auxBusInstance->NeedsRebuild(PlatformsToBuild, LanguagesToBuild, SoundBankInfoCache);

						auto& auxBusSet = infoEntry.AuxBusses;
						switch (InfoKind)
						{
						case FillAudioBankInfoKind::GUID:
							auxBusSet.Add(auxBusInstance->ID.ToString(EGuidFormats::DigitsWithHyphensInBraces));
							break;
						case FillAudioBankInfoKind::AssetName:
							auxBusSet.Add(auxBusInstance->GetName());
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}

	return FString::Join(BanksToGenerate, TEXT(" "));
}

bool AkSoundDataBuilder::fillBankDataInAsset(UAkAssetData* AssetData, const TArray<uint8>& NewBankData, FCriticalSection* DataLock)
{
	FScopeLock autoLock(DataLock);

	bool changed = false;
	auto newDataSize = NewBankData.Num();
	int64 currentSize = AssetData->Data.GetBulkDataSize();
	void* currentBankData = AssetData->Data.Lock(EBulkDataLockFlags::LOCK_READ_WRITE);
	if (currentSize != newDataSize || FMemory::Memcmp(NewBankData.GetData(), currentBankData, FMath::Min(static_cast<int64>(newDataSize), AssetData->Data.GetBulkDataSize())) != 0)
	{
		void* rawBankData = AssetData->Data.Realloc(newDataSize);
		FMemory::Memcpy(rawBankData, NewBankData.GetData(), newDataSize);
		changed = true;
	}

	AssetData->Data.Unlock();

	return changed;
}

void AkSoundDataBuilder::LoadAndWaitForAssetToLoad()
{
	if (IsRunningCommandlet())
	{
		return;
	}

	auto RequestAsyncLoadTask = FFunctionGraphTask::CreateAndDispatchWhenReady([sharedThis = SharedThis(this)]{
		if (auto AudioDevice = FAkAudioDevice::Get())
		{
			sharedThis->LoadedAssetsHandles.Empty();

			FScopedSlowTask SlowTask(1.f, FText::FromString("Loading events..."));
			SlowTask.Visibility = ESlowTaskVisibility::ForceVisible;
			SlowTask.OpenDialogThreshold = 0.f;

			TArray<FSoftObjectPath> AssetsToLoad;
			AssetsToLoad.Reserve(AkAssetDatabase::Get().AudioTypeMap.TypeMap.Num());

			for (auto& Entry : AkAssetDatabase::Get().AudioTypeMap.TypeMap)
			{
				AssetsToLoad.Add(Entry.Value.ToSoftObjectPath());
			}

			const int32 TotalAssetCount = AssetsToLoad.Num();

			// Load per batch of 100 events
			int32 BatchCount = 100;
			TArray<FSoftObjectPath> BatchToLoad;
			BatchToLoad.Reserve(BatchCount);
			int32 BatchStartIndex = 0;
			while (BatchStartIndex != TotalAssetCount)
			{
				BatchToLoad.Empty();
				const int32 LoadCount = FMath::Min(BatchCount, TotalAssetCount - BatchStartIndex);
				for (int32 IndexInBatch = 0; IndexInBatch < LoadCount; ++IndexInBatch)
				{
					BatchToLoad.Add(AssetsToLoad[BatchStartIndex + IndexInBatch]);
				}
				sharedThis->LoadedAssetsHandles.Add(AudioDevice->GetStreamableManager().RequestSyncLoad(BatchToLoad));
				SlowTask.EnterProgressFrame((float)LoadCount / (float)TotalAssetCount, FText::FromString(FString::Printf(TEXT("Loading Wwise Assets... (%i/%i)"), BatchStartIndex, TotalAssetCount)));
				BatchStartIndex += LoadCount;
			}
		}
		}, GET_STATID(STAT_EventPlatformDataEventGroup), nullptr, ENamedThreads::GameThread);
	FTaskGraphInterface::Get().WaitUntilTaskCompletes(RequestAsyncLoadTask);
}

TSet<UPackage*>& AkSoundDataBuilder::SaveAssetsBlocking()
{
	check(IsInGameThread());
	UEditorLoadingAndSavingUtils::SavePackages(PackagesToSave.Array(), true);
	return PackagesToSave;
}

#undef LOCTEXT_NAMESPACE
