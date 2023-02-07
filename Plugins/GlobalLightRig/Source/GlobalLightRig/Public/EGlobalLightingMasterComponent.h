#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingMasterComponent.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightingMasterComponent : uint8 {
    DirectionalLight,
    SecondaryDirectionalLight,
    SkyLight,
    SkyAtmosphere,
    ExponentialHeightFog,
    VolumetricClouds,
};

