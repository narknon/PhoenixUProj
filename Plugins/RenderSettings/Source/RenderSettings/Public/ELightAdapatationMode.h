#pragma once
#include "CoreMinimal.h"
#include "ELightAdapatationMode.generated.h"

UENUM(BlueprintType)
enum class ELightAdapatationMode : uint8 {
    LastFrameAutoExposure,
    LastFrameAverageLuminance,
    MinMaxExposureTarget,
    AutoAdaptation,
    AutoAdaptationBloom,
    FixedExposure,
};

