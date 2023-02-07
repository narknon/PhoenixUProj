#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EJumpingType.h"
#include "AblBranchConditionJumpType.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionJumpType : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EJumpingType::Type> JumpType;
    
public:
    UAblBranchConditionJumpType();
};

