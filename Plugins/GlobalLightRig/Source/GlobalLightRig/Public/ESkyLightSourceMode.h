#pragma once
#include "CoreMinimal.h"
#include "ESkyLightSourceMode.generated.h"

UENUM(BlueprintType)
enum class ESkyLightSourceMode : uint8 {
    CapturedScene,
    SpecifiedCubemap,
    RuntimeCapture,
    RuntimeRender,
    SkyAtmosphereCapturedScene,
};

