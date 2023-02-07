#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset_AssetProxy.generated.h"

USTRUCT(BlueprintType)
struct FBaseArchitectAsset_AssetProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AssetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ExternalName;
    
    ANIMATIONARCHITECTRUNTIME_API FBaseArchitectAsset_AssetProxy();
};

