#pragma once
#include "CoreMinimal.h"
#include "EIKDriver_GroundAdjustment_TraceShape.generated.h"

UENUM(BlueprintType)
enum class EIKDriver_GroundAdjustment_TraceShape : uint8 {
    Line,
    Box,
    Sphere,
    Capsule,
    EIKDriver_GroundAdjustment_MAX UMETA(Hidden),
};

