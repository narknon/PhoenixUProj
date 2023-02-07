#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingFogZMode.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightingFogZMode : uint8 {
    BaseOfVolume,
    CenterOfVolume,
    CameraZ,
    PlayerZ,
    WorldBase,
    OffsetOnly,
    OffsetIsAbsolute,
};

