#pragma once
#include "CoreMinimal.h"
#include "EStencilManagerEffectPriority.generated.h"

UENUM(BlueprintType)
enum class EStencilManagerEffectPriority : uint8 {
    AlwaysInterrupt,
    Low,
    BelowNormal,
    Normal,
    AboveNormal,
    High,
    VeryHigh,
    NeverInterrupt,
};

