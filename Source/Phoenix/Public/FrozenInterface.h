#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FrozenInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UFrozenInterface : public UInterface {
    GENERATED_BODY()
};

class IFrozenInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool StartFreeze(AActor* Instigator, float Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnThaw(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedToFreeze();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttemptToFreeze();
    
};

