#pragma once
#include "CoreMinimal.h"
#include "ENPC_AttackSelectionConditions.h"
#include "ENPC_SelectionStates.h"
#include "NPCAttackConditionValue.h"
#include "NPCAttackConditionalData.generated.h"

USTRUCT(BlueprintType)
struct FNPCAttackConditionalData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConditionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_SelectionStates ConditionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ENPC_AttackSelectionConditions, FNPCAttackConditionValue> EffectValues;
    
    PHOENIX_API FNPCAttackConditionalData();
};

