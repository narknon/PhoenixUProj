#pragma once
#include "CoreMinimal.h"
#include "WeatherVolume.h"
#include "WeatherDisableVolume.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherDisableVolume : public AWeatherVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableWeather;
    
    AWeatherDisableVolume();
};

