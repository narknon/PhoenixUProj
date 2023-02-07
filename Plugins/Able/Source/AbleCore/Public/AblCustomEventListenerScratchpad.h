#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblCustomEventListenerScratchpad.generated.h"

class UAblAbilityContext;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblCustomEventListenerScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UAblCustomEventListenerScratchpad();
    UFUNCTION(BlueprintCallable)
    void OnCustomEvent(const UAblAbilityContext* Context, const UAblAbilityContext* CallerContext, FName EventName);
    
};

