#pragma once
#include "CoreMinimal.h"
#include "WeatherDropdownName.h"
#include "WindDefinitionName.generated.h"

USTRUCT(BlueprintType)
struct FWindDefinitionName : public FWeatherDropdownName {
    GENERATED_BODY()
public:
    WEATHER_API FWindDefinitionName();
};

