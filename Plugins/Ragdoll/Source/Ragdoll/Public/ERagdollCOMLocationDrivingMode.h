#pragma once
#include "CoreMinimal.h"
#include "ERagdollCOMLocationDrivingMode.generated.h"

UENUM(BlueprintType)
enum class ERagdollCOMLocationDrivingMode : uint8 {
    NoDriving,
    DriveToCapsuleLocation,
    DriveToCapsuleHeight,
    DriveToCapsuleLocationAndKeepMoving,
    DriveToCapsuleHorizontalLocation,
    DampVelocity,
};

