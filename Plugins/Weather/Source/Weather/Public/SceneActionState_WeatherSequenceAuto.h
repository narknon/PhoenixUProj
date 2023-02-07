#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceAuto.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceAuto : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    USceneActionState_WeatherSequenceAuto();
};

