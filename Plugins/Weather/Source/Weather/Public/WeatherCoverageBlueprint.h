#pragma once
#include "CoreMinimal.h"
#include "WeatherSurfaceBlueprintBase.h"
#include "WeatherCoverageBlueprint.generated.h"

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherCoverageBlueprint : public AWeatherSurfaceBlueprintBase {
    GENERATED_BODY()
public:
    AWeatherCoverageBlueprint();
};

