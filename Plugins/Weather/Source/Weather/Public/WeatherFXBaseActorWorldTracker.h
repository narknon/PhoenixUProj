#pragma once
#include "CoreMinimal.h"
#include "WeatherFXBaseActorTracker.h"
#include "WeatherFXBaseActorWorldTracker.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FWeatherFXBaseActorWorldTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UWorld*, FWeatherFXBaseActorTracker> Trackers;
    
    WEATHER_API FWeatherFXBaseActorWorldTracker();
};

