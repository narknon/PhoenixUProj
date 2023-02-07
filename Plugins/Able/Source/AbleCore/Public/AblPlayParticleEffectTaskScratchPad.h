#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblPlayParticleEffectTaskScratchPad.generated.h"

class UParticleSystemComponent;

UCLASS(Blueprintable, NonTransient)
class UAblPlayParticleEffectTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UParticleSystemComponent>> SpawnedEffects;
    
    UAblPlayParticleEffectTaskScratchPad();
};

