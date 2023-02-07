#pragma once
#include "CoreMinimal.h"
#include "EAblMoveTaskVelocitySource.generated.h"

UENUM(BlueprintType)
enum class EAblMoveTaskVelocitySource : uint8 {
    Stratchpad,
    Fall,
    Custom,
    Ballistic,
};

