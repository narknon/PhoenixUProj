#pragma once
#include "CoreMinimal.h"
#include "EAttachCameraType.generated.h"

UENUM(BlueprintType)
enum class EAttachCameraType : uint8 {
    ACT_FULL,
    ACT_XYZ,
    ACT_XYONLY,
    ACT_BILLBOARD,
    ACT_ROTATION,
    ACT_MAX UMETA(Hidden),
};

