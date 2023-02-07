#pragma once
#include "CoreMinimal.h"
#include "DamageOverTime.h"
#include "CrucioComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCrucioComponent : public UDamageOverTime {
    GENERATED_BODY()
public:
    UCrucioComponent();
    UFUNCTION(BlueprintCallable)
    void SetupDelegate();
    
};

