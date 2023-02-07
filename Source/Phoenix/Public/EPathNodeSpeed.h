#pragma once
#include "CoreMinimal.h"
#include "EPathNodeSpeed.generated.h"

UENUM(BlueprintType)
enum class EPathNodeSpeed : uint8 {
    Stopped,
    SlowWalk,
    Walk,
    Jog,
    Sprint,
    Custom,
};

