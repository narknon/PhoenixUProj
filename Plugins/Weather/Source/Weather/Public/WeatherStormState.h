#pragma once
#include "CoreMinimal.h"
#include "WeatherStormParams.h"
#include "WeatherStormState.generated.h"

USTRUCT(BlueprintType)
struct FWeatherStormState : public FWeatherStormParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Age;
    
    WEATHER_API FWeatherStormState();
};

