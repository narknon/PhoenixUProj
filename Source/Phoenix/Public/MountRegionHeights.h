#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ERegionType.h"
#include "RegionHeightData.h"
#include "MountRegionHeights.generated.h"

UCLASS(Blueprintable)
class UMountRegionHeights : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightBuffer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, FRegionHeightData> HeightMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightRaiseInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightLowerInterpSpeed;
    
    UMountRegionHeights();
};

