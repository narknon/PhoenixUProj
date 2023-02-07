#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EObjectStateBranchCondition.h"
#include "AblObjectStateBranchCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblObjectStateBranchCondition : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EObjectStateBranchCondition ObjectStateBranchCondition;
    
public:
    UAblObjectStateBranchCondition();
};

