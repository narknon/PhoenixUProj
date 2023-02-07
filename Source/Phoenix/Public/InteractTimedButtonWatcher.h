#pragma once
#include "CoreMinimal.h"
#include "TimedButtonWatcher.h"
#include "InteractTimedButtonWatcher.generated.h"

class AActor;
class UAISense;

UCLASS(Blueprintable)
class UInteractTimedButtonWatcher : public UTimedButtonWatcher {
    GENERATED_BODY()
public:
    UInteractTimedButtonWatcher();
    UFUNCTION(BlueprintCallable)
    void TargetSighted(UAISense* Sense, const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void TargetChanged(UAISense* Sense, const AActor* NewTarget, const AActor* OldTarget);
    
};

