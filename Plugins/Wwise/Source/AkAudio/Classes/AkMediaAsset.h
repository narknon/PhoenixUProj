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

#include "Containers/IndirectArray.h"
#include "Core/Public/Templates/Function.h"
#include "Serialization/BulkData.h"
#include "UObject/Object.h"
#include "AkUEFeatures.h"
#include "AkMediaAsset.generated.h"

struct AKAUDIO_API FAkMediaDataChunk
{
	FAkMediaDataChunk();

#if WITH_EDITOR
	FAkMediaDataChunk(IFileHandle* FileHandle, int64 BytesToRead, uint32 BulkDataFlags, FCriticalSection* DataWriteLock, bool IsPrefetch = false);
#endif

	FByteBulkData Data;
	bool IsPrefetch = false;

	void Serialize(FArchive& Ar, UObject* Owner);
};

using MediaAssetDataLoadAsyncCallback = TFunction<void(uint8* MediaData, int64 MediaDataSize)>;

UCLASS()
class AKAUDIO_API UAkMediaAssetData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	bool IsStreamed = false;

	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	bool UseDeviceMemory = false;

	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	FString Language = "SFX";

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	int64 LastWriteTime = 0;

	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	uint64 MediaContentHash = 0;
#endif

	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	FString AssetPlatform;

	TIndirectArray<FAkMediaDataChunk> DataChunks;

#if WITH_EDITOR
	FCriticalSection DataLock;
#endif

	friend class UAkMediaAsset;
	friend class UAkExternalMediaAsset;

	enum class LoadState
	{
		Unloaded,
		Loading,
		Loaded,
		Error,
	};

	LoadState GetLoadState() const;
	FString StateToString() const;

public:
	void Serialize(FArchive& Ar) override;
	bool ExternalReadCallback(double RemainingTime);
	bool IsReadyForAsyncPostLoad() const override;
	void BeginDestroy() override;
	bool IsReadyForFinishDestroy() override;

	void LoadMediaAssetData(bool LoadAsync);
	void UnloadMediaAssetData();

	bool NeedsAutoLoading() const;
	bool IsLoaded() const { return State == LoadState::Loaded; }
	virtual void GetPreloadDependencies(TArray<UObject*>& OutDeps) override;

private:
	LoadState State;
	uint8* LoadedMediaData = nullptr;

	inline uint32 GetParentMediaId() const;
	inline FString GetParentMediaName() const;
	static bool IsCurrentWwisePlatform(const FString& AssetDataPlatform);

#if !WITH_EDITOR
	BulkDataIORequest* LoadingRequest = nullptr;
	void BulkDataStreamingRequestCompleted(bool bWasCancelled, ReadRequestArgumentType* ReadRequest);
#endif
};

UCLASS()
class AKAUDIO_API UAkMediaAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	uint32 Id;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	TMap<FString, UAkMediaAssetData*> MediaAssetDataPerPlatform;
#endif

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category = "AkMediaAsset")
	FString MediaName;

	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	bool AutoLoad = true;

	UPROPERTY(EditAnywhere, Category = "AkMediaAsset")
	TArray<UObject*> UserData;

	UPROPERTY(VisibleAnywhere, Category = "AkMediaAsset")
	FString Language = TEXT("SFX");

private:
	UPROPERTY(transient)
	UAkMediaAssetData* CurrentMediaAssetData;

public:
	void Serialize(FArchive& Ar) override;
	bool ExternalReadCallback(double RemainingTime);
	void PostLoad() override;

	void LoadMedia(bool bFromSerialize = false);
	void UnloadMedia();

	bool IsReadyForAsyncPostLoad() const override;

	bool bIsMediaSet = false;

#if WITH_EDITOR
	UAkMediaAssetData* FindOrAddMediaAssetData(const FString& Platform);

	virtual void Reset();

	FCriticalSection BulkDataWriteLock;
#endif

	FAkMediaDataChunk const* GetStreamedChunk() const;

	template<typename T>
	T* GetUserData()
	{
		for (auto Entry : UserData)
		{
			if (Entry && Entry->GetClass()->IsChildOf(T::StaticClass()))
			{
				return Entry;
			}
		}

		return nullptr;
	}
	friend class UAkMediaAssetData;

	UAkMediaAssetData::LoadState GetLoadState() const;
	FString GetLoadStateString() const;

protected:
	void LoadAndSetMedia(bool bLoadAsync);
	UAkMediaAssetData* GetMediaAssetData() const;

private:
	bool ForceAutoLoad = false;
	bool SerializeHasBeenCalled = false;
	bool LoadFromSerialize = false;

};

UCLASS()
class AKAUDIO_API UAkLocalizedMediaAsset : public UAkMediaAsset
{
	GENERATED_BODY()
};

UCLASS()
class AKAUDIO_API UAkExternalMediaAsset : public UAkMediaAsset
{
	GENERATED_BODY()

public:
	UAkExternalMediaAsset();

	void Serialize(FArchive& Ar) override;

	TTuple<void*, int64> GetExternalSourceData();
	FThreadSafeCounter NumStreamingHandles;

	void AddPlayingID(uint32 EventID, uint32 PlayingID);
	bool HasActivePlayingIDs();
	TMap<uint32, TArray<uint32>> ActiveEventToPlayingIDMap;

	void BeginDestroy() override;
	bool IsReadyForFinishDestroy() override;

	void PinInGarbageCollector(uint32 PlayingID);
	void UnpinFromGarbageCollector(uint32 PlayingID);

private:
	FThreadSafeCounter TimesPinnedToGC;
};

namespace AkMediaAssetHelpers
{
	AKAUDIO_API bool IsMediaReady(const TArray<UAkMediaAsset*>& InMediaList);
}
