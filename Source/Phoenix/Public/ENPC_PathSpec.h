#pragma once
#include "CoreMinimal.h"
#include "ENPC_PathSpec.generated.h"

UENUM(BlueprintType)
enum class ENPC_PathSpec : uint8 {
    None,
    Ground,
    Water,
    GroundAndWater,
    Custom,
    ENPC_MAX UMETA(Hidden),
};

