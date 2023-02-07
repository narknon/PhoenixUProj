#pragma once
#include "CoreMinimal.h"
#include "ENPC_LOSParamType.generated.h"

UENUM(BlueprintType)
enum class ENPC_LOSParamType : uint8 {
    None,
    Perception,
    Attack,
    Waypoint,
    ENPC_MAX UMETA(Hidden),
};

