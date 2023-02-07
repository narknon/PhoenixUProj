#pragma once
#include "CoreMinimal.h"
#include "EDayNightReportEmissiveAdaptation.generated.h"

UENUM(BlueprintType)
enum class EDayNightReportEmissiveAdaptation : uint8 {
    EmissiveAdaptationMinExposure,
    EmissiveAdaptationMaxExposure,
    EmissiveAdaptationTargetExposureEV,
    EmissiveAdaptationFinalMultiplier,
    EmissiveAdaptationOutdoorsDayTime,
    EmissiveAdaptationEnabled,
};

