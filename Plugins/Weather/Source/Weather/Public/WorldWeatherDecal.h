#pragma once
#include "CoreMinimal.h"
#include "WeatherDecal.h"
#include "WorldWeatherDecal.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWorldWeatherDecal : public UWeatherDecal {
    GENERATED_BODY()
public:
    UWorldWeatherDecal();
};

