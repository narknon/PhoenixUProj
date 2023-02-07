#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MunitionImpactData.h"
#include "SpellImpactComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USpellImpactComponent : public UActorComponent {
    GENERATED_BODY()
public:
    USpellImpactComponent();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellImpact(AActor* Target, const FMunitionImpactData& MunitionImpactData);
    
};

