#pragma once
#include "CoreMinimal.h"
#include "AblAbilityBaseScratchPad.h"
#include "AblAbilityEventScratchPad.generated.h"

class UAblAbilityEvent;
class UObject;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblAbilityEventScratchPad : public UAblAbilityBaseScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAblAbilityEvent> AbilityEventPtr;
    
    UAblAbilityEventScratchPad();
    UFUNCTION(BlueprintCallable)
    void EventReceived(const UObject* Caller);
    
};

