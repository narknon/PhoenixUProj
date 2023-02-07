#pragma once
#include "CoreMinimal.h"
#include "EPerformTaskSpeedMode.generated.h"

UENUM(BlueprintType)
enum class EPerformTaskSpeedMode : uint8 {
    Stopped,
    SlowWalk,
    Walk,
    Jog,
    MaxSpeedMode,
};

