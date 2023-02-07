/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2022 Audiokinetic Inc.
*******************************************************************************/
#pragma once

#include "UObject/Object.h"
#include <AK/SoundEngine/Common/AkTypes.h>
#include "Serialization/BulkData.h"

#include "AkAssetData.generated.h"

class UAkMediaAsset;
class UAkGroupValue;
class UAkAuxBus;
class UAkTrigger;
class UAkAudioEvent;
class ISoundBankInfoCache;

UCLASS()
class AKAUDIO_API UAkAssetData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "UAkAssetData")
	uint32 CachedHash;

	UPROPERTY(VisibleAnywhere, Category = "UAkAssetData")
	FString BankLanguage = "SFX";

	FByteBulkData Data;

public:
	void Serialize(FArchive& Ar) override;

	virtual AKRESULT LoadAssetData();
	virtual AKRESULT UnloadAssetData();

#if WITH_EDITOR
	virtual void GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& MediaList) const{};
#endif

	friend class AkEventBasedIntegrationBehavior;

protected:
	AkBankID BankID = AK_INVALID_BANK_ID;
	const void* RawData = nullptr;

#if WITH_EDITOR
	TArray<uint8> EditorRawData;
#endif


};

UCLASS()
class AKAUDIO_API UAkAssetDataWithMedia : public UAkAssetData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "UAkAssetData")
		TArray<UAkMediaAsset*> MediaList;

#if WITH_EDITOR
	TArray<TSoftObjectPtr<UAkMediaAsset>> TempMediaList;

	virtual void FillTempMediaList();
	virtual void FillFinalMediaList();

	void GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& MediaList) const override;
#endif
};

UCLASS()
class AKAUDIO_API UAkAssetPlatformData : public UObject
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category = "UAkAssetData")
	TMap<FString, UAkAssetData*> AssetDataPerPlatform;
#endif

	UPROPERTY(transient)
	UAkAssetData* CurrentAssetData;

public:
	void Serialize(FArchive& Ar) override;
	void GetPreloadDependencies(TArray<UObject*>& OutDeps) override;

#if WITH_EDITOR
	void Reset();

	bool NeedsRebuild(const TSet<FString>& PlatformsToBuild, const FString& Language, const FGuid& ID, const ISoundBankInfoCache* SoundBankInfoCache) const;

	void GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& MediaList) const;
#endif
};


UCLASS(EditInlineNew)
class AKAUDIO_API UAkAssetDataSwitchContainerData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "AkAudioEventData")
		TSoftObjectPtr<UAkGroupValue> GroupValue;

	UPROPERTY(VisibleAnywhere, Category = "AkAudioEventData")
		UAkGroupValue* DefaultGroupValue;

	UPROPERTY(VisibleAnywhere, Category = "AkAudioEventData")
		TArray<UAkMediaAsset*> MediaList;

	UPROPERTY(VisibleAnywhere, Category = "AkAudioEventData")
		TArray<UAkAssetDataSwitchContainerData*> Children;

	friend class UAkAssetDataSwitchContainer;


public:
	bool IsReadyForAsyncPostLoad() const override;
	bool IsMediaReady();

#if WITH_EDITOR
	TArray<TSoftObjectPtr<UAkMediaAsset>> TempMediaList;

	void FillTempMediaList();
	void FillFinalMediaList();

	void GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& mediaList) const;
#endif

private:
	void internalGetMediaList(const UAkAssetDataSwitchContainerData* data, TArray<TSoftObjectPtr<UAkMediaAsset>>& mediaList) const;
};

UCLASS()
class AKAUDIO_API UAkAssetDataSwitchContainer : public UAkAssetDataWithMedia
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "SwitchContainerData")
		TArray<UAkAssetDataSwitchContainerData*> SwitchContainers;

	UPROPERTY(VisibleAnywhere, Category = "SwitchContainerData")
		UAkGroupValue* DefaultGroupValue;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category = "UAkAssetData")
		FString AssetPlatform;
#endif

public:
	void Serialize(FArchive& Ar);
	bool IsReadyForAsyncPostLoad() const override;
	void BeginDestroy() override;
	virtual void GetPreloadDependencies(TArray<UObject*>& OutDeps) override;

#if WITH_EDITOR
	void FillTempMediaList() override;
	void FillFinalMediaList() override;
	void GetMediaList(TArray<TSoftObjectPtr<UAkMediaAsset>>& mediaList) const override;
#endif

	void LoadSwitchContainers();
	void UnloadSwitchContainers();
	bool IsMediaReady();

private:
	void LoadSwitchContainer(const TArray<UAkAssetDataSwitchContainerData*>& SwitchContainersToLoad);
	void LoadSwitchContainer(UAkAssetDataSwitchContainerData* SwitchContainer);

	void UnloadSwitchContainerMedia(const TArray<UAkAssetDataSwitchContainerData*>& switchContainers);
	void UnloadSwitchContainerMedia(UAkAssetDataSwitchContainerData* switchContainer);

	void OnSwitchValueLoaded(UAkGroupValue* NewGroupValue);

	TMap<uint32, UAkAssetDataSwitchContainerData*> PendingSwitchLoads;
};

UCLASS()
class AKAUDIO_API UAkAudioEventData : public UAkAssetDataSwitchContainer
{
	GENERATED_BODY()

public:
	/** Maximum attenuation radius for this event */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioEventData")
		float MaxAttenuationRadius;

	/** Whether this event is infinite (looping) or finite (duration parameters are valid) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioEventData")
		bool IsInfinite;

	/** Minimum duration */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioEventData")
		float MinimumDuration;

	/** Maximum duration */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioEventData")
		float MaximumDuration;

	// This map is used when the event is part of a AkAudioBank
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "Localized media data "))
	TMap<FString, UAkAssetDataSwitchContainer*> LocalizedMedia_DEPRECATED;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioEventData")
		TSet<UAkAudioEvent*> PostedEvents;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioEventData")
		TSet<UAkAuxBus*> UserDefinedSends;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioEventData")
		TSet<UAkTrigger*> PostedTriggers;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AkAudioEventData")
		TSet<UAkGroupValue*> GroupValues;
};