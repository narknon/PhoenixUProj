#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblTargetTrackerTaskScratchPad.generated.h"

class UTargetTracker;

UCLASS(Blueprintable, NonTransient)
class UAblTargetTrackerTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTargetTracker* TargetTracker;
    
    UAblTargetTrackerTaskScratchPad();
};

