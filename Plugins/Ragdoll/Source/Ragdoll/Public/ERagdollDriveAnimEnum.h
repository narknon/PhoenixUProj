#pragma once
#include "CoreMinimal.h"
#include "ERagdollDriveAnimEnum.generated.h"

UENUM(BlueprintType)
enum class ERagdollDriveAnimEnum : uint8 {
    DriveHoldPriorLastPose,
    DriveKeepPrior,
    DriveToAnim,
    DriveToGetupPose,
};

