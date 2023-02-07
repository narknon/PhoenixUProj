#pragma once
#include "CoreMinimal.h"
#include "EWeatherSeasonFilter.generated.h"

UENUM(BlueprintType)
enum class EWeatherSeasonFilter : uint8 {
    Fall,
    Winter,
    Spring,
    Summer,
};

