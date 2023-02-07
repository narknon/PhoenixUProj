#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalUpdateSingleParameterFlex.h"
#include "WeatherDecalUpdateFlexBlend.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalUpdateFlexBlend : public UWeatherDecalUpdateSingleParameterFlex {
    GENERATED_BODY()
public:
    UWeatherDecalUpdateFlexBlend();
};

