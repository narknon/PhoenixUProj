#pragma once
#include "CoreMinimal.h"
#include "EDayNightReportLighting.generated.h"

UENUM(BlueprintType)
enum class EDayNightReportLighting : uint8 {
    DirLightAzi,
    DirLightAlt,
    DirLightIntensity,
    DirLightColor,
    DirLightIndirectIntensity,
    DirLightSpecularScale,
    DirLightLightShaftBloom,
    DirLightLightShaftOcclusion,
    SkyLightIntensity,
    SkyLightIndirectIntensity,
};

