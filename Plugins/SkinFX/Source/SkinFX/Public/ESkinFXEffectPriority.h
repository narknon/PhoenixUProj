#pragma once
#include "CoreMinimal.h"
#include "ESkinFXEffectPriority.generated.h"

UENUM(BlueprintType)
enum class ESkinFXEffectPriority : uint8 {
    NeverInterrupt,
    VeryHigh,
    High,
    Normal,
    Low,
    AlwaysInterrupt,
};

