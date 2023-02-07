#pragma once
#include "CoreMinimal.h"
#include "AblAbilityBaseScratchPad.h"
#include "AblAbilityTaskScratchPad.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class ABLECORE_API UAblAbilityTaskScratchPad : public UAblAbilityBaseScratchPad {
    GENERATED_BODY()
public:
    UAblAbilityTaskScratchPad();
};

