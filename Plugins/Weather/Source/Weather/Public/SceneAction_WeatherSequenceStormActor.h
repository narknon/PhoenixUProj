#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequence.h"
#include "Templates/SubclassOf.h"
#include "SceneAction_WeatherSequenceStormActor.generated.h"

class AWeatherSurfaceWorldFXBlueprint;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceStormActor : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AWeatherSurfaceWorldFXBlueprint> StormActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Transform;
    
    USceneAction_WeatherSequenceStormActor();
};

