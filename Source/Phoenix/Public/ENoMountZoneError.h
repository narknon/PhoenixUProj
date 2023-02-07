#pragma once
#include "CoreMinimal.h"
#include "ENoMountZoneError.generated.h"

UENUM(BlueprintType)
enum class ENoMountZoneError : uint8 {
    Error_OutOfBounds,
    Error_NoFlyZone,
    Error_NoMountZone,
    Error_LeavingRaceTrack,
    Error_LeavingArea,
    Error_AbandoningRace,
    Error_MAX UMETA(Hidden),
};

