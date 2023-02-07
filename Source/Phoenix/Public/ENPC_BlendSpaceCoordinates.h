#pragma once
#include "CoreMinimal.h"
#include "ENPC_BlendSpaceCoordinates.generated.h"

UENUM(BlueprintType)
enum class ENPC_BlendSpaceCoordinates : uint8 {
    Cartesian,
    Polar,
    Anim,
    MoveTurn,
    Standard,
    ENPC_MAX UMETA(Hidden),
};

