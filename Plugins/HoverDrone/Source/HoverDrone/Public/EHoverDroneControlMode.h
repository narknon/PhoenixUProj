#pragma once
#include "CoreMinimal.h"
#include "EHoverDroneControlMode.generated.h"

UENUM(BlueprintType)
namespace EHoverDroneControlMode {
    enum Type {
        Player,
        HoverDrone,
        FollowCam,
        MAX,
    };
}

