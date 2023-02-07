#pragma once
#include "CoreMinimal.h"
#include "ESkinFXColorConvert.generated.h"

UENUM(BlueprintType)
enum class ESkinFXColorConvert : uint8 {
    None,
    CLAMP,
    QUANTIZE,
    FROMHSB,
    XYZ,
    XYZW,
    XY,
    XYZWPAIR,
    PYRFORWARD,
    PYRUP,
    PYRRIGHT,
    RANGLE,
    RGANGLE,
};

