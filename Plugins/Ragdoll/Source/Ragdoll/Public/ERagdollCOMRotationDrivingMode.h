#pragma once
#include "CoreMinimal.h"
#include "ERagdollCOMRotationDrivingMode.generated.h"

UENUM(BlueprintType)
enum class ERagdollCOMRotationDrivingMode : uint8 {
    NoDriving,
    DriveToCapsuleRotation,
    DriveToKeepUpright,
};

