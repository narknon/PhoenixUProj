#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityCategory.generated.h"

UENUM(BlueprintType)
enum class EPhoenixScalabilityCategory : uint8 {
    ViewDistance,
    AntiAliasing,
    Shadow,
    PostProcess,
    Texture,
    Effects,
    Foliage,
    Shading,
    Volumetrics,
    Sky,
    Population,
};

