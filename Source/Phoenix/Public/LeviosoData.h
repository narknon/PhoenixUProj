#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "LeviosoData.generated.h"

class UCurveFloat;
class UCurveVector;
class UInteractionArchitectAsset;
class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FLeviosoData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* HoverTargetOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveVector* HoverTargetRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> DataAssetArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTagContainer;
    
    PHOENIX_API FLeviosoData();
};

