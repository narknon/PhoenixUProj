#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AnimationArchitectAsset_AssetProxy.h"
#include "BaseArchitectAsset_Connection.h"
#include "AnimationArchitectAsset_Connection.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FAnimationArchitectAsset_Connection : public FBaseArchitectAsset_Connection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationArchitectAsset_AssetProxy> AssetProxies;
    
    FAnimationArchitectAsset_Connection();
};

