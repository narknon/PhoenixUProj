#pragma once
#include "CoreMinimal.h"
#include "WeatherSurfaceFogBase.h"
#include "WeatherSurfaceFogSimple.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherSurfaceFogSimple : public AWeatherSurfaceFogBase {
    GENERATED_BODY()
public:
    AWeatherSurfaceFogSimple(const FObjectInitializer& ObjectInitializer);
};

