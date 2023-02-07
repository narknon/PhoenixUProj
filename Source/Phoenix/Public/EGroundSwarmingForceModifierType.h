#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingForceModifierType.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmingForceModifierType : uint8 {
    Follow,
    Separation,
    SeparationDistance,
    Alignment,
    Cohesion,
    MaxSpeed,
    CurlNoiseScale,
    Velocity,
};

