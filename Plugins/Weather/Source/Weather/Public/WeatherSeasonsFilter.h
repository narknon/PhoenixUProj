#pragma once
#include "CoreMinimal.h"
#include "WeatherSeasonsFilter.generated.h"

USTRUCT(BlueprintType)
struct FWeatherSeasonsFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seasons;
    
    WEATHER_API FWeatherSeasonsFilter();
};

