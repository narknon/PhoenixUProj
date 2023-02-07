#pragma once
#include "CoreMinimal.h"
#include "EDayNightBlendOps.generated.h"

UENUM(BlueprintType)
enum class EDayNightBlendOps : uint8 {
    DirectionalLightDirection,
    DirectionalLightBasic,
    DirectionalLightShafts,
    SkyLightBasic,
    SkyLightHemisphere,
    SkyAtmosphere,
    VolumetricCloudsBasic,
    VolumetricCloudsAdvanced,
    VolumetricCloudsShadow,
    VolumetricCloudsSkyLight,
    VolumetricCloudsGroundShadow,
    VolumetricCloudsSceneLight,
    ProbeLightingAdjustment,
    ProbeLightingToneMap,
    ProbeContactShadows,
};

