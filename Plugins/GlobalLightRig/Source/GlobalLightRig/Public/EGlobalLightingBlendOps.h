#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingBlendOps.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightingBlendOps : uint8 {
    LightDirection,
    LightParameters,
    SecondaryLightDirection,
    SecondaryLightParameters,
    SkyLightParameters,
    ExpHeightFogParameters,
    CloudsLightingParameters,
    CloudsPresetParameters,
    CloudsWindParameters,
    ProbeLightingParameters,
    SkyAtmosphereParameters,
    CustomBlendables,
};

