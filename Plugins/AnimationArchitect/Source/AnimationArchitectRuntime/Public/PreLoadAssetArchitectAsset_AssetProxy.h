#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset_AssetProxy.h"
#include "PreLoadAssetArchitectAsset_AssetProxy.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FPreLoadAssetArchitectAsset_AssetProxy : public FBaseArchitectAsset_AssetProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ObjectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    FPreLoadAssetArchitectAsset_AssetProxy();
};

