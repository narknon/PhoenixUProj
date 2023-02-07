#pragma once
#include "CoreMinimal.h"
#include "ERootMotionModTurnAssistUseDirection.generated.h"

UENUM(BlueprintType)
namespace ERootMotionModTurnAssistUseDirection {
    enum Type {
        FacingTarget_OR_DesiredDirection,
        FallLine,
        DesiredDirectionOnly,
        JumpStartVelocityOnly,
        FallLineWithinRange,
    };
}

