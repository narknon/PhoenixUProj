#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "Name_GameLogicBoolResult.h"
#include "AblBranchConditionGameLogic.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionGameLogic : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicBoolResult BoolResultName;
    
public:
    UAblBranchConditionGameLogic();
};

