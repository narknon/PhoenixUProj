#pragma once
#include "CoreMinimal.h"
#include "CreatureCombatStageSpecifier.generated.h"

USTRUCT(BlueprintType)
struct FCreatureCombatStageSpecifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxNumChainedAttacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumBehaviorCyclesBeforeReposition;
    
    PHOENIX_API FCreatureCombatStageSpecifier();
};

