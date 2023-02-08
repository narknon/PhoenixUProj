#pragma once
#include "CoreMinimal.h"
#include "AblAbilityEventScratchPad.h"
#include "AblAbilityAnimNotifyEventScratchPad.generated.h"

class UAblAbilityContext;


UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblAbilityAnimNotifyEventScratchPad : public UAblAbilityEventScratchPad {
    GENERATED_BODY()
public:
    UAblAbilityAnimNotifyEventScratchPad();
    UFUNCTION(BlueprintCallable)
    void OnAnimationPlayed(float InCurrentTime, const UAnimationAsset* InAnimationAsset, const UAblAbilityContext* Context);
    
};

