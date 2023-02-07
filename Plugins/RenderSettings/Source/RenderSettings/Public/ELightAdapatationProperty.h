#pragma once
#include "CoreMinimal.h"
#include "ELightAdapatationProperty.generated.h"

UENUM(BlueprintType)
enum class ELightAdapatationProperty : uint8 {
    BaseEV,
    OutdoorsDayTimeEVBoost,
    AdaptationStrengthPercent,
    MinMaxExposureTarget,
    MaxEV,
    MinEV,
    StartCutoffMaxEV,
    StartCutoffMinEV,
};

