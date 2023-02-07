#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset_AssetProxy.h"
#include "StationArchitectAsset_AssetProxy.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FStationArchitectAsset_AssetProxy : public FBaseArchitectAsset_AssetProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* StationAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    FStationArchitectAsset_AssetProxy();
};

