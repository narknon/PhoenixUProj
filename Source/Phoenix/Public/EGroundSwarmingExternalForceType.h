#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingExternalForceType.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmingExternalForceType : uint8 {
    Forward,
    Up,
    Right,
    Radial,
    RadialTangentUp,
    CurlNoise,
};

