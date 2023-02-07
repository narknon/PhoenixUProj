#pragma once
#include "CoreMinimal.h"
#include "WeatherSequenceName.h"
#include "WeatherSequenceNoRedirectorsName.generated.h"

USTRUCT(BlueprintType)
struct FWeatherSequenceNoRedirectorsName : public FWeatherSequenceName {
    GENERATED_BODY()
public:
    WEATHER_API FWeatherSequenceNoRedirectorsName();
};

