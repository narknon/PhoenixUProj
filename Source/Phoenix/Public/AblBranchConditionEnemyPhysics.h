#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionEnemyPhysics.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionEnemyPhysics : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnPhysicsMovementStop;
    
public:
    UAblBranchConditionEnemyPhysics();
};

