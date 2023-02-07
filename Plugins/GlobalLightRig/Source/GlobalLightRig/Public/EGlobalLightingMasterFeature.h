#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingMasterFeature.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightingMasterFeature : uint8 {
    ProbeLighting,
    CloudsLighting,
    CloudsPreset,
    CloudsWind,
    CloudsSceneLightDirection,
    CloudsSceneLightColor,
    CloudsSceneLightIntensity,
    CloudsSceneLightSaturation,
};

