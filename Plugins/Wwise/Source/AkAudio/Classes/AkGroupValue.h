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

#include "AkAudioType.h"
#include "AkGroupValue.generated.h"

class UAkMediaAsset;

UCLASS()
class AKAUDIO_API UAkGroupValue : public UAkAudioType
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, AssetRegistrySearchable, Category = "AkGroupValue")
	FGuid GroupID;
#endif
	
	UPROPERTY(VisibleAnywhere, Category = "AkGroupValue")
	TArray<TSoftObjectPtr<UAkMediaAsset>> MediaDependencies;

	UPROPERTY(VisibleAnywhere, AssetRegistrySearchable, Category = "AkGroupValue")
	uint32 GroupShortID;

public:
	void PostLoad() override;

	void BeginDestroy() override;
	void Serialize(FArchive& Ar) override;
	bool ExternalReadCallback(double RemainingTime, TSoftObjectPtr<UAkMediaAsset> Media);
	bool IsReadyForAsyncPostLoad() const override;

#if WITH_EDITOR
	void Reset(TArray<FAssetData>& InOutAssetsToDelete) override;
#endif

private:
	TArray<TWeakObjectPtr<UAkMediaAsset>> LoadedMediaDependencies;
};
