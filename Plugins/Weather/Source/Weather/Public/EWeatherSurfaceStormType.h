#pragma once
#include "CoreMinimal.h"
#include "EWeatherSurfaceStormType.generated.h"

UENUM(BlueprintType)
enum class EWeatherSurfaceStormType : uint8 {
    None,
    Light,
    Normal,
    Heavy,
    Torrential,
};

