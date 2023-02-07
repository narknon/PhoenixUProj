#pragma once
#include "CoreMinimal.h"
#include "EOrientationTargetKind.generated.h"

UENUM(BlueprintType)
enum class EOrientationTargetKind : uint8 {
    Direction,
    Location,
};

