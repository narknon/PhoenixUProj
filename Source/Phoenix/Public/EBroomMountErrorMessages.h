#pragma once
#include "CoreMinimal.h"
#include "EBroomMountErrorMessages.generated.h"

UENUM(BlueprintType)
enum class EBroomMountErrorMessages : uint8 {
    Error_BroomDisabled,
    Error_InsideNoMountingZone,
    Error_InsideNoMountingArea,
    Error_SpeedBoostUnavailable,
    Error_SpeedBoostOnCooldown,
    Error_InsufficientSpawnArea,
    Error_MAX UMETA(Hidden),
};

