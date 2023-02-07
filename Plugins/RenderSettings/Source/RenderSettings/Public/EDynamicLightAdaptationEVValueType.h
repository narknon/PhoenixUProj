#pragma once
#include "CoreMinimal.h"
#include "EDynamicLightAdaptationEVValueType.generated.h"

UENUM(BlueprintType)
enum class EDynamicLightAdaptationEVValueType : uint8 {
    Absolute,
    MinMaxExposureTarget,
    LastFrameAverageLuminanceDelta,
    AutoAdaptationDelta,
    AutoAdaptationBloomDelta,
};

