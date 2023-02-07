#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblTaskConditionScratchpad_DamageOverTime.generated.h"

class UActorComponent;

UCLASS(Blueprintable, NonTransient)
class UAblTaskConditionScratchpad_DamageOverTime : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UAblTaskConditionScratchpad_DamageOverTime();
    UFUNCTION(BlueprintCallable)
    void OnDoT_End(UActorComponent* ActorComp);
    
};

