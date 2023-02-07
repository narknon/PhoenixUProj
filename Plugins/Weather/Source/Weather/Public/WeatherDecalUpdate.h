#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalModifier.h"
#include "WeatherDecalUpdate.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalUpdate : public UWeatherDecalModifier {
    GENERATED_BODY()
public:
    UWeatherDecalUpdate();
};

