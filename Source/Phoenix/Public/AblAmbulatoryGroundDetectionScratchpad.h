#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblAmbulatoryGroundDetectionScratchpad.generated.h"

class UAmbulatory_MovementComponent;

UCLASS(Blueprintable, NonTransient)
class UAblAmbulatoryGroundDetectionScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAmbulatory_MovementComponent* MovementComp;
    
    UAblAmbulatoryGroundDetectionScratchpad();
};

