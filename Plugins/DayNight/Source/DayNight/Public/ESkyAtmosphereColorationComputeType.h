#pragma once
#include "CoreMinimal.h"
#include "ESkyAtmosphereColorationComputeType.generated.h"

UENUM(BlueprintType)
enum class ESkyAtmosphereColorationComputeType : uint8 {
    SkyColorOnly,
    SunLightOnly,
    MoonLightOnly,
    DirLightOnly,
    SunLit,
    MoonLit,
    DirLit,
};

