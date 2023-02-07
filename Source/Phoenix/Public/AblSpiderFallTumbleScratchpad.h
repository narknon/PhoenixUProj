#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblSpiderFallTumbleScratchpad.generated.h"

class UAmbulatory_MovementComponent;

UCLASS(Blueprintable, NonTransient)
class UAblSpiderFallTumbleScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAmbulatory_MovementComponent* AmbulatoryMovementComponent;
    
    UAblSpiderFallTumbleScratchpad();
};

