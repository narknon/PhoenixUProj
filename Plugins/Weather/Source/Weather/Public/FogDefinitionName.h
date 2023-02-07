#pragma once
#include "CoreMinimal.h"
#include "WeatherDropdownName.h"
#include "FogDefinitionName.generated.h"

USTRUCT(BlueprintType)
struct FFogDefinitionName : public FWeatherDropdownName {
    GENERATED_BODY()
public:
    WEATHER_API FFogDefinitionName();
};

