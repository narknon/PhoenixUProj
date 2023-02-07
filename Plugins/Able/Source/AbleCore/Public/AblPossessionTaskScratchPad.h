#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblPossessionTaskScratchPad.generated.h"

class APlayerController;

UCLASS(Blueprintable, NonTransient)
class UAblPossessionTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerController> PossessorController;
    
    UAblPossessionTaskScratchPad();
};

