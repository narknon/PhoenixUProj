#pragma once
#include "CoreMinimal.h"
#include "EDayNightReportExposure.generated.h"

UENUM(BlueprintType)
enum class EDayNightReportExposure : uint8 {
    ExposureMinMax,
    ExposureBias,
    ExposureHistMinMax,
    ExposureSpeed,
    ExposureLowHighPercent,
    ExposureLastFrameLuminance,
    ExposureLastFrameExposure,
    ExposureLastFrameBright,
};

