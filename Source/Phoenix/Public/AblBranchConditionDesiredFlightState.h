#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "ECreatureFlightState.h"
#include "AblBranchConditionDesiredFlightState.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionDesiredFlightState : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureFlightState DesiredFlightState;
    
    UAblBranchConditionDesiredFlightState();
};

