#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblBranchConditionTimer_New.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionTimer_New : public UAblTaskCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTime;
    
public:
    UAblBranchConditionTimer_New();
};

