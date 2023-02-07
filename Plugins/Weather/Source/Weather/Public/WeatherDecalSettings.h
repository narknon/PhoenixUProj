#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalModifier.h"
#include "WeatherDecalSettings.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalSettings : public UWeatherDecalModifier {
    GENERATED_BODY()
public:
    UWeatherDecalSettings();
};

