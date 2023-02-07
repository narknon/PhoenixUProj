#pragma once
#include "CoreMinimal.h"
#include "EWeatherSurfacePrecipitation.generated.h"

UENUM(BlueprintType)
enum class EWeatherSurfacePrecipitation : uint8 {
    None,
    Rain,
    Snow,
};

