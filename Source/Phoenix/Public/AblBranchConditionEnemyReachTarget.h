#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionEnemyReachTarget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionEnemyReachTarget : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyTriggerOnGroundMatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnGroundRequirement;
    
public:
    UAblBranchConditionEnemyReachTarget();
};

