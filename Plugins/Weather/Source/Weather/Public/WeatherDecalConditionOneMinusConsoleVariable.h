#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalConditionConsoleVariable.h"
#include "WeatherDecalConditionOneMinusConsoleVariable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalConditionOneMinusConsoleVariable : public UWeatherDecalConditionConsoleVariable {
    GENERATED_BODY()
public:
    UWeatherDecalConditionOneMinusConsoleVariable();
};

