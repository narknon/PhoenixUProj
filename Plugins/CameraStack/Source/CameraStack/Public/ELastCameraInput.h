#pragma once
#include "CoreMinimal.h"
#include "ELastCameraInput.generated.h"

UENUM(BlueprintType)
enum class ELastCameraInput : uint8 {
    None,
    Look,
    MouseLook,
    Tilt,
};

