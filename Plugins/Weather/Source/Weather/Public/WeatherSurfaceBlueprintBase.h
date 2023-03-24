#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherStormState.h"
#include "WeatherSurfaceBlueprintBase.generated.h"

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherSurfaceBlueprintBase : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherStormState StormState;
    
    AWeatherSurfaceBlueprintBase(const FObjectInitializer& ObjectInitializer);
};

