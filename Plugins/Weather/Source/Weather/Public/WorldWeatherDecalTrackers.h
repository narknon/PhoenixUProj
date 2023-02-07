#pragma once
#include "CoreMinimal.h"
#include "WorldWeatherDecalTrackers.generated.h"

class UWeatherDecal;
class UWeatherDecalTracker;

USTRUCT(BlueprintType)
struct FWorldWeatherDecalTrackers {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UWeatherDecal>, UWeatherDecalTracker*> Trackers;
    
    WEATHER_API FWorldWeatherDecalTrackers();
};

