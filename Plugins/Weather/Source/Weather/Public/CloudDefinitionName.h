#pragma once
#include "CoreMinimal.h"
#include "WeatherDropdownName.h"
#include "CloudDefinitionName.generated.h"

USTRUCT(BlueprintType)
struct FCloudDefinitionName : public FWeatherDropdownName {
    GENERATED_BODY()
public:
    WEATHER_API FCloudDefinitionName();
};

