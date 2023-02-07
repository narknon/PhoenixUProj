#pragma once
#include "CoreMinimal.h"
#include "SurfaceFogActorTracker.generated.h"

class AWeatherSurfaceFogBase;

USTRUCT(BlueprintType)
struct FSurfaceFogActorTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AWeatherSurfaceFogBase*> Actors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AWeatherSurfaceFogBase*> CurrentlyActivated;
    
    WEATHER_API FSurfaceFogActorTracker();
};

