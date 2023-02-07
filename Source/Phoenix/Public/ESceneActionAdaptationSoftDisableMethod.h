#pragma once
#include "CoreMinimal.h"
#include "ESceneActionAdaptationSoftDisableMethod.generated.h"

UENUM(BlueprintType)
enum class ESceneActionAdaptationSoftDisableMethod : uint8 {
    MinExposure,
    AverageMinMaxExposure,
    Zero,
    NegativeTwenty,
};

