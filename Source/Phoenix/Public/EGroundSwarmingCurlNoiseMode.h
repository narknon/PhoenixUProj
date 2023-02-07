#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingCurlNoiseMode.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmingCurlNoiseMode : uint8 {
    None,
    Simple2D,
    Faux3D,
    Local2D,
    Expensive3D,
};

