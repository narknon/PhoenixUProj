#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblPlayObjectArchitectVfxScratchpad.generated.h"

class UAblTaskConditionScratchpad;
class UNiagaraComponent;
class UParticleSystemComponent;

UCLASS(Blueprintable, NonTransient)
class UAblPlayObjectArchitectVfxScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ParticleComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskConditionScratchpad*> ConditionScratchpads;
    
    UAblPlayObjectArchitectVfxScratchpad();
};

