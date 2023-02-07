#pragma once
#include "CoreMinimal.h"
#include "EDesiredDeltaTargetTracker.generated.h"

UENUM(BlueprintType)
namespace EDesiredDeltaTargetTracker {
    enum Type {
        DesiredDirection,
        LastDesiredDirection,
        Facing,
        LookAt,
        AimAt,
        StrafeDirection,
        VelocityDirection,
        BufferedDesiredDirection,
    };
}

