#pragma once
#include "CoreMinimal.h"
#include "WeatherSurfaceBlueprintBase.h"
#include "WeatherAnimationBlueprint.generated.h"

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherAnimationBlueprint : public AWeatherSurfaceBlueprintBase {
    GENERATED_BODY()
public:
    AWeatherAnimationBlueprint(const FObjectInitializer& ObjectInitializer);
};

