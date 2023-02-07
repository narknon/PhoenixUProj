#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "WeatherVolume.generated.h"

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherVolume : public AVolume {
    GENERATED_BODY()
public:
    AWeatherVolume();
};

