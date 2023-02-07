#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModParamFamily.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightRigModParamFamily : uint8 {
    NoFamily,
    DirectionalLightDirection,
    DirectionalLightParameters,
    SkyLight,
    SkyAtmosphere,
    CloudLighting,
    CloudsWind,
    ProbeLighting,
    ExponentialHeightFog,
};

