#pragma once
#include "CoreMinimal.h"
#include "WeatherWorldTime.h"
#include "WeatherWorldTimeEditor.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherWorldTimeEditor : public FWeatherWorldTime {
    GENERATED_BODY()
public:
    FWeatherWorldTimeEditor();
};

