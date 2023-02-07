#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblCameraStackAnimationTaskScratchPad.generated.h"

class UAnimSequence;

UCLASS(Blueprintable, NonTransient)
class UAblCameraStackAnimationTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequence* ChosenAnimSequence;
    
    UAblCameraStackAnimationTaskScratchPad();
};

