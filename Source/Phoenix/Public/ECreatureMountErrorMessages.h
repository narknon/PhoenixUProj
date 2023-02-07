#pragma once
#include "CoreMinimal.h"
#include "ECreatureMountErrorMessages.generated.h"

UENUM(BlueprintType)
enum class ECreatureMountErrorMessages : uint8 {
    Error_GraphornDisabled,
    Error_HippogriffDisabled,
    Error_TakeOffUnavailable,
    Error_ChargeUnavailable,
    Error_ChargeOnCooldown,
    Error_InsufficientSpawnArea,
    Error_MountDeathCooldown,
    Error_InsideNoTakeOffZone,
    Error_InsideNoLandZone,
    Error_InsideNoMountingZone,
    Error_InsideNoMountingArea,
    Error_MAX UMETA(Hidden),
};

