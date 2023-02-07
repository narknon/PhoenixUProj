#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EAbilityTaskScratchPadCondition.h"
#include "AblBranchConditionEnemyCase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionEnemyCase : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAbilityTaskScratchPadCondition Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float fMinTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float fMaxTime;
    
public:
    UAblBranchConditionEnemyCase();
};

