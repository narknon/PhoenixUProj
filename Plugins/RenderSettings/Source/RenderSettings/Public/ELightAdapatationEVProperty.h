#pragma once
#include "CoreMinimal.h"
#include "ELightAdapatationEVProperty.generated.h"

UENUM(BlueprintType)
enum class ELightAdapatationEVProperty : uint8 {
    BaseEV,
    OutdoorsDayTimeEVBoost,
    MaxEV,
    MinEV,
    StartCutoffMaxEV,
    StartCutoffMinEV,
};

