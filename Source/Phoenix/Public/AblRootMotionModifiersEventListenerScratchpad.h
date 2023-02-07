#pragma once
#include "CoreMinimal.h"
#include "AblCustomEventListenerStartEndScratchpad.h"
#include "AblRootMotionModifiersEventListenerScratchpad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblRootMotionModifiersEventListenerScratchpad : public UAblCustomEventListenerStartEndScratchpad {
    GENERATED_BODY()
public:
    UAblRootMotionModifiersEventListenerScratchpad();
};

