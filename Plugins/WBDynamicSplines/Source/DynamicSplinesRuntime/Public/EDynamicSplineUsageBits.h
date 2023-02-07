#pragma once
#include "CoreMinimal.h"
#include "EDynamicSplineUsageBits.generated.h"

UENUM(BlueprintType)
enum class EDynamicSplineUsageBits : uint8 {
    None,
    Positions,
    Normals,
    Tangents = 0x4,
    WorldSpace = 0x8,
};

