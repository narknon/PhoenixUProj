#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "ERightArmPriority.h"
#include "ERightArmState.h"
#include "AblBranchConditionRightArmState.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionRightArmState : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<ERightArmState::Type>> RightArmStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERightArmPriority::Type> RightArmPriority;
    
public:
    UAblBranchConditionRightArmState();
};

