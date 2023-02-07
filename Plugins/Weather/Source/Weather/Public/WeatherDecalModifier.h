#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeatherDecalModifier.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class WEATHER_API UWeatherDecalModifier : public UObject {
    GENERATED_BODY()
public:
    UWeatherDecalModifier();
};

