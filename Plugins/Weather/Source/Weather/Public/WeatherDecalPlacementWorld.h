#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalPlacement.h"
#include "WeatherDecalPlacementWorld.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalPlacementWorld : public UWeatherDecalPlacement {
    GENERATED_BODY()
public:
    UWeatherDecalPlacementWorld();
};

