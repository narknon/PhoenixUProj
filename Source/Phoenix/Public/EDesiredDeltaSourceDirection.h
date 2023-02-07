#pragma once
#include "CoreMinimal.h"
#include "EDesiredDeltaSourceDirection.generated.h"

UENUM(BlueprintType)
namespace EDesiredDeltaSourceDirection {
    enum Type {
        FacingDirection,
        DesiredDirection,
        Facing,
        LookAt,
        AimAt,
        StrafeDirection,
        VelocityDirection,
    };
}

