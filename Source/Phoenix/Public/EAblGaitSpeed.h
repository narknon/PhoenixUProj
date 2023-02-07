#pragma once
#include "CoreMinimal.h"
#include "EAblGaitSpeed.generated.h"

UENUM(BlueprintType)
enum class EAblGaitSpeed : uint8 {
    Stopped,
    SlowWalk,
    Walk,
    Jog,
    Sprint,
};

