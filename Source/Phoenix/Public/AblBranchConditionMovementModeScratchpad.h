#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblBranchConditionMovementModeScratchpad.generated.h"

class UCharacterMovementComponent;

UCLASS(Blueprintable, NonTransient)
class UAblBranchConditionMovementModeScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterMovementComponent* MovementComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeInMode;
    
    UAblBranchConditionMovementModeScratchpad();
};

