#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceStormActor.generated.h"

class AWeatherSurfaceWorldFXBlueprint;

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceStormActor : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AWeatherSurfaceWorldFXBlueprint> SpawnedActor;
    
    USceneActionState_WeatherSequenceStormActor();
};

