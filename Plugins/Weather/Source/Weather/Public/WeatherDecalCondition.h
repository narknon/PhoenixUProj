#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeatherDecalCondition.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class WEATHER_API UWeatherDecalCondition : public UObject {
    GENERATED_BODY()
public:
    UWeatherDecalCondition();
};

