#pragma once
#include "CoreMinimal.h"
#include "WeatherDecal.h"
#include "StormWeatherDecal.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UStormWeatherDecal : public UWeatherDecal {
    GENERATED_BODY()
public:
    UStormWeatherDecal();
};

