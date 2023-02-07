#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalTracker.h"
#include "WeatherStormState.h"
#include "StormWeatherDecalTracker.generated.h"

class AWeatherAnimationBlueprint;
class AWeatherCoverageBlueprint;
class UWorld;

UCLASS(Blueprintable, NonTransient)
class WEATHER_API UStormWeatherDecalTracker : public UWeatherDecalTracker {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorld> OwningWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherStormState StormState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWeatherAnimationBlueprint* AnimationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWeatherCoverageBlueprint* CoverageActor;
    
    UStormWeatherDecalTracker();
};

