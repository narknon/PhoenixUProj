#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchBlackboardBoolCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchBlackboardBoolCondition : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlackboardKeyName;
    
public:
    UAblBranchBlackboardBoolCondition();
};

