#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset_AssetProxy.h"
#include "InteractionArchitectAsset_AssetProxy.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FInteractionArchitectAsset_AssetProxy : public FBaseArchitectAsset_AssetProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* GeneratedClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    FInteractionArchitectAsset_AssetProxy();
};

