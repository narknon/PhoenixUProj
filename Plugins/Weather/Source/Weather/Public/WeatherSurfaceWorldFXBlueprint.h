#pragma once
#include "CoreMinimal.h"
#include "WeatherSurfaceBlueprintBase.h"
#include "WeatherSurfaceWorldFXBlueprint.generated.h"

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherSurfaceWorldFXBlueprint : public AWeatherSurfaceBlueprintBase {
    GENERATED_BODY()
public:
    AWeatherSurfaceWorldFXBlueprint(const FObjectInitializer& ObjectInitializer);
};

