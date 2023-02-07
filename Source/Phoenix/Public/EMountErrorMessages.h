#pragma once
#include "CoreMinimal.h"
#include "EMountErrorMessages.generated.h"

UENUM(BlueprintType)
enum class EMountErrorMessages : uint8 {
    Error_EnteringNoFlyZone,
    Error_EnteringNoGroundZone,
    Error_EnteringNoMountsZone,
    Error_InsideNoDismountZone,
    Error_SpeedUpUnavailable,
    Error_LandingUnavailable,
    Error_MAX UMETA(Hidden),
};

