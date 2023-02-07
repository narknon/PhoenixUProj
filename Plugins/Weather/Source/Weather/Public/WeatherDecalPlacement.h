#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeatherDecalPlacement.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class WEATHER_API UWeatherDecalPlacement : public UObject {
    GENERATED_BODY()
public:
    UWeatherDecalPlacement();
};

