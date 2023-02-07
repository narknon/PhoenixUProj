#pragma once
#include "CoreMinimal.h"
#include "EWeatherSurfaceCharacterFXParameters.generated.h"

UENUM(BlueprintType)
enum class EWeatherSurfaceCharacterFXParameters : uint8 {
    None,
    LocalCoverage,
    LocalCoverageRate,
    LocalDrying,
    CachedIndoors,
    StormCoverage,
    StormIntensity,
    StormPrecipitation,
    StormType,
    StormAge,
};

