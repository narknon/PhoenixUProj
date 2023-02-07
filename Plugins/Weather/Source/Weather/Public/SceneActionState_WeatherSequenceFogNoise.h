#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequenceAuto.h"
#include "SceneActionState_WeatherSequenceFogNoise.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceFogNoise : public USceneActionState_WeatherSequenceAuto {
    GENERATED_BODY()
public:
    USceneActionState_WeatherSequenceFogNoise();
};

