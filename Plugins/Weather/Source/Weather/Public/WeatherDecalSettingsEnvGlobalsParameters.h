#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalSettingsParameters.h"
#include "WeatherDecalSettingsEnvGlobalsParameters.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalSettingsEnvGlobalsParameters : public UWeatherDecalSettingsParameters {
    GENERATED_BODY()
public:
    UWeatherDecalSettingsEnvGlobalsParameters();
};

