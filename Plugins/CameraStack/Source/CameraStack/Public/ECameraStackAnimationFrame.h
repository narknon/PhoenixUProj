#pragma once
#include "CoreMinimal.h"
#include "ECameraStackAnimationFrame.generated.h"

UENUM(BlueprintType)
enum class ECameraStackAnimationFrame : uint8 {
    World,
    RelativeToTarget,
    RelativeToTargetInitialTransform,
    RelativeToTargetWorldRotation,
    RelativeToCameraYaw,
    RelativeToCameraRotation,
    Additive,
    RelativeToSecondaryTarget,
};

