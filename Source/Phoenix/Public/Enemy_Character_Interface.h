#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Enemy_Character_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UEnemy_Character_Interface : public UInterface {
    GENERATED_BODY()
};

class IEnemy_Character_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MunitionCreated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventTrackMeleePoints();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AttackWindowStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AttackWindowStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AttackLeftCollisionStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AttackLeftCollisionStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AttackCollisionStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AttackCollisionStart();
    
};

