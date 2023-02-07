#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblBranchConditionSlopeSlideDoneScratchpad.generated.h"

class UAmbulatory_MovementComponent;

UCLASS(Blueprintable, NonTransient)
class UAblBranchConditionSlopeSlideDoneScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAmbulatory_MovementComponent* MovementComp;
    
    UAblBranchConditionSlopeSlideDoneScratchpad();
};

