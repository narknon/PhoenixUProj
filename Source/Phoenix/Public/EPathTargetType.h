#pragma once
#include "CoreMinimal.h"
#include "EPathTargetType.generated.h"

UENUM(BlueprintType)
enum class EPathTargetType : uint8 {
    PATH_TARGET_NONE,
    PATH_TARGET_STATIC,
    PATH_TARGET_DYNAMIC,
    PATH_TARGET_BEACON,
    PATH_TARGET_WAYPOINT,
    PATH_TARGET_MAX UMETA(Hidden),
};

