#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EAnimMechanicType.h"
#include "AblBranchConditionAnimMechanic.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionAnimMechanic : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAnimMechanicType::Type> AnimMechanicType;
    
public:
    UAblBranchConditionAnimMechanic();
};

