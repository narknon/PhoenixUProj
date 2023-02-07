#pragma once
#include "CoreMinimal.h"
#include "ECreatureStance.generated.h"

UENUM(BlueprintType)
enum class ECreatureStance : uint8 {
    Standing,
    Sitting,
    LyingDown,
    Sleeping,
    Flying,
};

