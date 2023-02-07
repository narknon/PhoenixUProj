#pragma once
#include "CoreMinimal.h"
#include "BaseWatcher.h"
#include "ButtonWatcher.generated.h"

class UWatcherRecord;

UCLASS(Blueprintable)
class CONTROLMAPPER_API UButtonWatcher : public UBaseWatcher {
    GENERATED_BODY()
public:
    UButtonWatcher();
    UFUNCTION(BlueprintCallable)
    void ModifierChanged(bool NewResult);
    
    UFUNCTION(BlueprintCallable)
    void FlushQueuedActions(UWatcherRecord* InWatcherRecord);
    
    UFUNCTION(BlueprintCallable)
    void ExpressionChanged(bool NewResult);
    
    UFUNCTION(BlueprintCallable)
    void ButtonReleased();
    
    UFUNCTION(BlueprintCallable)
    void ButtonPressed();
    
    UFUNCTION(BlueprintCallable)
    void ActionInitiate();
    
    UFUNCTION(BlueprintCallable)
    void ActionCancel();
    
};

