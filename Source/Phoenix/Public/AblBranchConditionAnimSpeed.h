#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EAnimSpeedType.h"
#include "AblBranchConditionAnimSpeed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionAnimSpeed : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAnimSpeedType::Type> AnimSpeedType;
    
public:
    UAblBranchConditionAnimSpeed();
};

