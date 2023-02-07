#pragma once
#include "CoreMinimal.h"
#include "MapFXBase.h"
#include "MapFXChain.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable)
class UMapFXChain : public UMapFXBase {
    GENERATED_BODY()
public:
    UMapFXChain();
private:
    UFUNCTION(BlueprintCallable)
    void OnFinished(UNiagaraComponent* PSystem);
    
public:
    UFUNCTION(BlueprintCallable)
    void FXTimerCallback();
    
};

