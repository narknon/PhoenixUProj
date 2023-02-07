#pragma once
#include "CoreMinimal.h"
#include "ESceneRigRenderingCuts.generated.h"

UENUM(BlueprintType)
enum class ESceneRigRenderingCuts : uint8 {
    Camera,
    Exposure,
    PreExposure,
    Fog,
    SkyLight,
    AudioListener,
};

