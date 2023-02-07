#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeatherDefinitions.generated.h"

UCLASS(Blueprintable)
class WEATHER_API UWeatherDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UWeatherDefinitions();
};

