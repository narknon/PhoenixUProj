#pragma once
#include "CoreMinimal.h"
#include "ESkinFXEnvelopeState.generated.h"

UENUM(BlueprintType)
enum class ESkinFXEnvelopeState : uint8 {
    Done,
    Attack,
    Sustain,
    Release,
    InfiniteSustain,
};

