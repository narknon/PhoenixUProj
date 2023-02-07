#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TransformationOverlandData.generated.h"

class UInteractionArchitectAsset;
class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FTransformationOverlandData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> HideFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> SpawnFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> UnspawnFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> RestoreFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RestoreMunitionTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* RestoreMunitionDataAsset;
    
    PHOENIX_API FTransformationOverlandData();
};

