#pragma once
#include "CoreMinimal.h"
#include "WeatherDropdownName.h"
#include "WeatherCustomSequenceName.generated.h"

USTRUCT(BlueprintType)
struct FWeatherCustomSequenceName : public FWeatherDropdownName {
    GENERATED_BODY()
public:
    WEATHER_API FWeatherCustomSequenceName();
};

