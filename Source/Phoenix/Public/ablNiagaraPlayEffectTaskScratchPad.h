#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablNiagaraPlayEffectTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablNiagaraPlayEffectTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablNiagaraPlayEffectTaskScratchPad();
};

