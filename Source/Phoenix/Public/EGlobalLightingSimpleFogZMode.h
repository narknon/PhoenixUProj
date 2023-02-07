#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingSimpleFogZMode.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightingSimpleFogZMode : uint8 {
    OffsetOnly,
    OffsetIsAbsolute,
    CameraZ,
    PlayerZ,
    SceneRigTransform,
    WorldBase,
};

