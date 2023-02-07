#pragma once
#include "CoreMinimal.h"
#include "WeatherDropdownName.h"
#include "WeatherSequenceName.generated.h"

USTRUCT(BlueprintType)
struct FWeatherSequenceName : public FWeatherDropdownName {
    GENERATED_BODY()
public:
    WEATHER_API FWeatherSequenceName();
};

