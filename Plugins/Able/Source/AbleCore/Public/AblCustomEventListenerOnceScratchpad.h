#pragma once
#include "CoreMinimal.h"
#include "AblCustomEventListenerScratchpad.h"
#include "AblCustomEventListenerOnceScratchpad.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblCustomEventListenerOnceScratchpad : public UAblCustomEventListenerScratchpad {
    GENERATED_BODY()
public:
    UAblCustomEventListenerOnceScratchpad();
};

