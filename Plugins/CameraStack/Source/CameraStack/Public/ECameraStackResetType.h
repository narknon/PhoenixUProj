#pragma once
#include "CoreMinimal.h"
#include "ECameraStackResetType.generated.h"

UENUM(BlueprintType)
enum class ECameraStackResetType : uint8 {
    NoReset,
    FullReset,
    CurrentCameraDirection,
    CurrentCameraYawAndDefaultPitch,
    LookAtLocation,
    FixedArmRotation,
    FullResetWithOffset,
};

