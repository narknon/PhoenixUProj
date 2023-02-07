#pragma once
#include "CoreMinimal.h"
#include "ELerpVolumesInterpolantType.generated.h"

UENUM(BlueprintType)
enum class ELerpVolumesInterpolantType : uint8 {
    Unknown,
    Scalar,
    Integer,
    Vector,
    UnitDirection,
    Color,
    Tag,
};

