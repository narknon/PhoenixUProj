#pragma once
#include "CoreMinimal.h"
#include "ETurnAssistUseDirection.generated.h"

UENUM(BlueprintType)
namespace ETurnAssistUseDirection {
    enum Type {
        FacingTarget_OR_DesiredDirection,
        FallLine,
        DesiredDirectionOnly,
        JumpStartVelocityOnly,
        FallLineWithinRange,
    };
}

