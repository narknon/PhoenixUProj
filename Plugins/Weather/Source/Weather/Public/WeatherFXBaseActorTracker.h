#pragma once
#include "CoreMinimal.h"
#include "WeatherFXBaseActorTracker.generated.h"

class AWeatherStormFXBase;

USTRUCT(BlueprintType)
struct FWeatherFXBaseActorTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AWeatherStormFXBase*> Actors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AWeatherStormFXBase*> CurrentlyActivated;
    
    WEATHER_API FWeatherFXBaseActorTracker();
};

