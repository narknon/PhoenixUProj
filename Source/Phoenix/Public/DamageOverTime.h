#pragma once
#include "CoreMinimal.h"
#include "StateEffectComponent.h"
#include "DamageOverTime.generated.h"

class UActorComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDamageOverTime : public UStateEffectComponent {
    GENERATED_BODY()
public:
    UDamageOverTime();
protected:
    UFUNCTION(BlueprintCallable)
    void OnArrestoEnd(UActorComponent* i_component);
    
};

