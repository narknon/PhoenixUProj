#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblBranchMovementPredictedEventScratchpad.generated.h"

class UMovementPredictionComponent;

UCLASS(Blueprintable, NonTransient)
class UAblBranchMovementPredictedEventScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMovementPredictionComponent* MovementPredictionComponent;
    
    UAblBranchMovementPredictedEventScratchpad();
};

