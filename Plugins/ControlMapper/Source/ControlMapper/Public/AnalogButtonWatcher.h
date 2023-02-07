#pragma once
#include "CoreMinimal.h"
#include "ButtonWatcher.h"
#include "AnalogButtonWatcher.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UAnalogButtonWatcher : public UButtonWatcher {
    GENERATED_BODY()
public:
    UAnalogButtonWatcher();
    UFUNCTION(BlueprintCallable)
    void AnalogValue(float AxisVal);
    
};

