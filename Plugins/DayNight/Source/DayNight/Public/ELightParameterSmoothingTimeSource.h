#pragma once
#include "CoreMinimal.h"
#include "ELightParameterSmoothingTimeSource.generated.h"

UENUM(BlueprintType)
enum class ELightParameterSmoothingTimeSource : uint8 {
    RealTime,
    TimeOfDay,
    NormalizedTime,
};

