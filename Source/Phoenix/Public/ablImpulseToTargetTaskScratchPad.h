#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablImpulseToTargetTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablImpulseToTargetTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablImpulseToTargetTaskScratchPad();
};

