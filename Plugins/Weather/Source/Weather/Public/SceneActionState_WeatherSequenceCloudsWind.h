#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequenceAuto.h"
#include "SceneActionState_WeatherSequenceCloudsWind.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceCloudsWind : public USceneActionState_WeatherSequenceAuto {
    GENERATED_BODY()
public:
    USceneActionState_WeatherSequenceCloudsWind();
};

