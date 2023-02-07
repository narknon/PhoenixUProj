#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CreatureCombatAttackImpactData.generated.h"

class UCreatureCombatAttackData;

USTRUCT(BlueprintType)
struct FCreatureCombatAttackImpactData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatAttackData* AttackData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimationArchitectGameplayTags;
    
    PHOENIX_API FCreatureCombatAttackImpactData();
};

