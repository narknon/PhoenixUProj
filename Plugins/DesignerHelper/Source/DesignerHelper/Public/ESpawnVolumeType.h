#pragma once
#include "CoreMinimal.h"
#include "ESpawnVolumeType.generated.h"

UENUM(BlueprintType)
enum class ESpawnVolumeType : uint8 {
    Point,
    Box,
    Sphere,
    Capsule,
    Spline,
};

