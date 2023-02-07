#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FiniteInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UFiniteInterface : public UInterface {
    GENERATED_BODY()
};

class IFiniteInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartFinite(AActor* Instigator, bool RemovedEffect);
    
};

