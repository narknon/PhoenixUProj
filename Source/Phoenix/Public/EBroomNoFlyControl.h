#pragma once
#include "CoreMinimal.h"
#include "EBroomNoFlyControl.generated.h"

UENUM(BlueprintType)
enum class EBroomNoFlyControl : uint8 {
    NOFLY_Default,
    NOFLY_PUSH,
    NOFLY_180,
    NOFLY_TELEPORT,
    NOFLY_SLOWDOWN,
    NOFLY_HUG,
    NOFLY_NONE,
    NOFLY_COUNT,
    NOFLY_MAX UMETA(Hidden),
};

