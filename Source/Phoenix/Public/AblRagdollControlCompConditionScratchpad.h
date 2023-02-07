#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblRagdollControlCompConditionScratchpad.generated.h"

class UIcarus3DMovementComponent;
class URagdollControlComponent;

UCLASS(Blueprintable, NonTransient)
class UAblRagdollControlCompConditionScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URagdollControlComponent* RagdollControlComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIcarus3DMovementComponent* FlightMovementComp;
    
    UAblRagdollControlCompConditionScratchpad();
};

