#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblNpcBakedPoseRigidbodyScratchpad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblNpcBakedPoseRigidbodyScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UAblNpcBakedPoseRigidbodyScratchpad();
    UFUNCTION(BlueprintCallable)
    void OnBakedRigidBodyAttachedEvent();
    
};

