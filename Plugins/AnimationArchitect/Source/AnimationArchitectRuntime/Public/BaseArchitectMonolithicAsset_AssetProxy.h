#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectMonolithicAsset_AssetProxy.generated.h"

USTRUCT(BlueprintType)
struct FBaseArchitectMonolithicAsset_AssetProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AssetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    ANIMATIONARCHITECTRUNTIME_API FBaseArchitectMonolithicAsset_AssetProxy();
};

