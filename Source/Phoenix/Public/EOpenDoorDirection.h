#pragma once
#include "CoreMinimal.h"
#include "EOpenDoorDirection.generated.h"

UENUM(BlueprintType)
enum class EOpenDoorDirection : uint8 {
    AwayFromPlayer,
    Clockwise,
    CounterClockwise,
};

