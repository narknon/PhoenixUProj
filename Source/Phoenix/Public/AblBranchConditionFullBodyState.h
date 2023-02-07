#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EFullBodyState.h"
#include "AblBranchConditionFullBodyState.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionFullBodyState : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFullBodyState::Type> FullBodyState;
    
public:
    UAblBranchConditionFullBodyState();
};

