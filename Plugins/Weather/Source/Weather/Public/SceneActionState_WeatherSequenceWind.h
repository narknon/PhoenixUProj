#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequenceAuto.h"
#include "SceneActionState_WeatherSequenceWind.generated.h"

class UWeatherWindDirectionalSourceComponent;

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceWind : public USceneActionState_WeatherSequenceAuto {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWeatherWindDirectionalSourceComponent> WindSource;
    
    USceneActionState_WeatherSequenceWind();
};

