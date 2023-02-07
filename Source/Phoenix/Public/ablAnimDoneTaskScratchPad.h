#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablAnimDoneTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablAnimDoneTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablAnimDoneTaskScratchPad();
};

