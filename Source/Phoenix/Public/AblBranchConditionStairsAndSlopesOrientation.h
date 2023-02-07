#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionStairsAndSlopesOrientation.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionStairsAndSlopesOrientation : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinAngle;
    
public:
    UAblBranchConditionStairsAndSlopesOrientation();
};

