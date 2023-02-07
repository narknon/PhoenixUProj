#pragma once
#include "CoreMinimal.h"
#include "ESkyAtmosphereColorationComputeOutput.generated.h"

UENUM(BlueprintType)
enum class ESkyAtmosphereColorationComputeOutput : uint8 {
    Composited,
    ColorOnly,
    IntensityOnly,
    ColorRGBIntensityA,
};

