#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset_AssetProxy.h"
#include "AnimationArchitectAsset_AssetProxy.generated.h"



USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FAnimationArchitectAsset_AssetProxy : public FBaseArchitectAsset_AssetProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* AnimationAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    FAnimationArchitectAsset_AssetProxy();
};

