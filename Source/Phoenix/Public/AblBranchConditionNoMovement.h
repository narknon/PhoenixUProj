#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionNoMovement.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionNoMovement : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceSquaredTolerance;
    
public:
    UAblBranchConditionNoMovement();
};

