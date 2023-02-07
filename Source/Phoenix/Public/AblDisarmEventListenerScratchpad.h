#pragma once
#include "CoreMinimal.h"
#include "AblCustomEventListenerOnceScratchpad.h"
#include "AblDisarmEventListenerScratchpad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblDisarmEventListenerScratchpad : public UAblCustomEventListenerOnceScratchpad {
    GENERATED_BODY()
public:
    UAblDisarmEventListenerScratchpad();
};

