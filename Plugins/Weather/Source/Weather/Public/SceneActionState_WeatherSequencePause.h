#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequencePause.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequencePause : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    USceneActionState_WeatherSequencePause();
};

