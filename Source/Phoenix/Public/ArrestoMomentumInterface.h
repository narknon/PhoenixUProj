#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ArrestoMomentumInterface.generated.h"

class AActor;
class UArrestoMomentumComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class UArrestoMomentumInterface : public UInterface {
    GENERATED_BODY()
};

class IArrestoMomentumInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnArrestoMomentumEnd(AActor* Instigator, UArrestoMomentumComponent* ArrestoMomentumComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnArrestoMomentumBegin(AActor* Instigator, UArrestoMomentumComponent* ArrestoMomentumComponent, float TimeDilation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisallowArrestoMomentum();
    
};

