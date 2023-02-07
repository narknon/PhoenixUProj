#pragma once
#include "CoreMinimal.h"
#include "EPreviewMode.generated.h"

UENUM(BlueprintType)
enum class EPreviewMode : uint8 {
    NONE,
    DEFAULT,
    WEATHER_COVERAGE,
    WEATHER_TYPE,
    WEATHER_PRECIPITATION,
};

