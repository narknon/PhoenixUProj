#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DOTData.generated.h"

class UInteractionArchitectAsset;
class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FDOTData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> MunitionDataAssetArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    PHOENIX_API FDOTData();
};

