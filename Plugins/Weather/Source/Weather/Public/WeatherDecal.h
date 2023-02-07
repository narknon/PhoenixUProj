#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeatherDecal.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class WEATHER_API UWeatherDecal : public UObject {
    GENERATED_BODY()
public:
    UWeatherDecal();
};

