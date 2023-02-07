#pragma once
#include "CoreMinimal.h"
#include "ENPC_AttackSelectionConditions.h"
#include "NPCAttackConditionValue.generated.h"

USTRUCT(BlueprintType)
struct FNPCAttackConditionValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_AttackSelectionConditions WeightType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeightValue;
    
    PHOENIX_API FNPCAttackConditionValue();
};

