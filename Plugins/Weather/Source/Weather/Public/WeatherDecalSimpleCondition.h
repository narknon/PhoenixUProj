#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalCondition.h"
#include "WeatherDecalSimpleCondition.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalSimpleCondition : public UWeatherDecalCondition {
    GENERATED_BODY()
public:
    UWeatherDecalSimpleCondition();
};

