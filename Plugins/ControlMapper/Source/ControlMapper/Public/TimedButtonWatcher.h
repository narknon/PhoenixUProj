#pragma once
#include "CoreMinimal.h"
#include "ButtonWatcher.h"
#include "TimedButtonWatcher.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UTimedButtonWatcher : public UButtonWatcher {
    GENERATED_BODY()
public:
    UTimedButtonWatcher();
    UFUNCTION(BlueprintCallable)
    void SetChargeTime(float InChargeTime);
    
    UFUNCTION(BlueprintCallable)
    float RestoreChargeTime();
    
    UFUNCTION(BlueprintCallable)
    void ActionStop();
    
};

