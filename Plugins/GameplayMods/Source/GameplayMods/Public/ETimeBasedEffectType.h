#pragma once
#include "CoreMinimal.h"
#include "ETimeBasedEffectType.generated.h"

UENUM(BlueprintType)
enum class ETimeBasedEffectType : uint8 {
    UnaffectedByTimeCurve,
    TimeCurveEvaluatedByCurrentTime,
    TimeCurveEvaluatedByNormalizedTime,
};

