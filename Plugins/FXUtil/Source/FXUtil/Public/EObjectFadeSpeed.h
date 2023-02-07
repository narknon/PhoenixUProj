#pragma once
#include "CoreMinimal.h"
#include "EObjectFadeSpeed.generated.h"

UENUM(BlueprintType)
enum class EObjectFadeSpeed : uint8 {
    VeryFast,
    Fast,
    Default,
    Slow,
    VerySlow,
};

