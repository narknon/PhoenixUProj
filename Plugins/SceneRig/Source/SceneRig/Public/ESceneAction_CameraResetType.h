#pragma once
#include "CoreMinimal.h"
#include "ESceneAction_CameraResetType.generated.h"

UENUM(BlueprintType)
enum class ESceneAction_CameraResetType : uint8 {
    NoReset,
    BehindAvatar,
    CurrentCameraDirection,
    CurrentCameraYawAndDefaultPitch,
    LookAtLocation,
    ESceneAction_MAX UMETA(Hidden),
};

