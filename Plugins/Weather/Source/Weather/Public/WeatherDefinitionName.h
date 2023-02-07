#pragma once
#include "CoreMinimal.h"
#include "WeatherDropdownName.h"
#include "WeatherDefinitionName.generated.h"

USTRUCT(BlueprintType)
struct FWeatherDefinitionName : public FWeatherDropdownName {
    GENERATED_BODY()
public:
    WEATHER_API FWeatherDefinitionName();
};

