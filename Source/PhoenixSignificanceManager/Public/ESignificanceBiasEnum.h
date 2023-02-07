#pragma once
#include "CoreMinimal.h"
#include "ESignificanceBiasEnum.generated.h"

UENUM(BlueprintType)
enum class ESignificanceBiasEnum : uint8 {
    SIGNIFICANCE_BIAS_LOW,
    SIGNIFICANCE_BIAS_DEFAULT,
    SIGNIFICANCE_BIAS_HIGH,
    SIGNIFICANCE_BIAS_CRITICAL,
    SIGNIFICANCE_BIAS_MAX UMETA(Hidden),
};

