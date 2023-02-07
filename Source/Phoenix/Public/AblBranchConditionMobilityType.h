#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EMobilityActionState.h"
#include "AblBranchConditionMobilityType.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionMobilityType : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMobilityActionState::Type> MobilityActionState;
    
public:
    UAblBranchConditionMobilityType();
};

