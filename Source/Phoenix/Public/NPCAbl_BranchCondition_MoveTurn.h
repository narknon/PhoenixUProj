#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "NPCAbl_BranchCondition_MoveTurn.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UNPCAbl_BranchCondition_MoveTurn : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinThresholdAngleDeg;
    
public:
    UNPCAbl_BranchCondition_MoveTurn();
};

