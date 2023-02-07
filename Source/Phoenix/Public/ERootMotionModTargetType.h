#pragma once
#include "CoreMinimal.h"
#include "ERootMotionModTargetType.generated.h"

UENUM(BlueprintType)
enum class ERootMotionModTargetType : uint8 {
    FaceTracker,
    AimAtTracker,
    LookAtTracker,
};

