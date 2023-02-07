#pragma once
#include "CoreMinimal.h"
#include "EExposureExpressionsExtraTarget.generated.h"

UENUM(BlueprintType)
enum class EExposureExpressionsExtraTarget : uint8 {
    MaterialPC,
    NiagaraPC,
    External,
};

