#pragma once
#include "CoreMinimal.h"
#include "AblAbilityBaseScratchPad.h"
#include "AblAbilityChannelingScratchPad.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class ABLECORE_API UAblAbilityChannelingScratchPad : public UAblAbilityBaseScratchPad {
    GENERATED_BODY()
public:
    UAblAbilityChannelingScratchPad();
};

