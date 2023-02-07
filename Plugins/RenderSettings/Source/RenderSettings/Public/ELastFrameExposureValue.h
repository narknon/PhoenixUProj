#pragma once
#include "CoreMinimal.h"
#include "ELastFrameExposureValue.generated.h"

UENUM(BlueprintType)
enum class ELastFrameExposureValue : uint8 {
    AverageLuminance,
    AverageHistogramLuminance,
    AutoExposure,
    Brightness,
    FilteredAverageLuminance,
    FilteredAverageHistogramLuminance,
    FilteredAutoExposure,
    FilteredBrightness,
};

