#pragma once
#include "CoreMinimal.h"
#include "ELightParameterSmoothingTimeBase.generated.h"

UENUM(BlueprintType)
enum class ELightParameterSmoothingTimeBase : uint8 {
    Seconds,
    Minutes,
    Hours,
};

