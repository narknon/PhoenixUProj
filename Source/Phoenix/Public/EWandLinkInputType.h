#pragma once
#include "CoreMinimal.h"
#include "EWandLinkInputType.generated.h"

UENUM(BlueprintType)
enum class EWandLinkInputType : uint8 {
    LeftShoulderButton,
    RightShoulderButton,
    LeftTriggerButton,
    RightTriggerButton,
    LeftAndRightShoulderButton,
    LeftAndRightTriggerButton,
    RandomWingButton,
    LeftFaceButton,
    TopFaceButton,
    RightFaceButton,
    BottomFaceButton,
    RandomFaceButton,
};

