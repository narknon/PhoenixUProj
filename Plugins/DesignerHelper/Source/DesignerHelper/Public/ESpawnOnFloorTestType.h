#pragma once
#include "CoreMinimal.h"
#include "ESpawnOnFloorTestType.generated.h"

UENUM(BlueprintType)
enum class ESpawnOnFloorTestType : uint8 {
    ShapeSweep,
    LineTrace,
};

