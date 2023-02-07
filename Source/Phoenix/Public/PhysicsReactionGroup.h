#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ENoiseSize.h"
#include "PhysicsReactionGroup.generated.h"

class UInteractionArchitectAsset;
class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FPhysicsReactionGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDamageThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* MunitionDataLevelAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ImpactStrengthTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENoiseSize NoiseSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> CollisionFX2;
    
    PHOENIX_API FPhysicsReactionGroup();
};

