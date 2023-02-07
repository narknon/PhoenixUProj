#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequenceAuto.h"
#include "SceneActionState_WeatherSequenceFog.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceFog : public USceneActionState_WeatherSequenceAuto {
    GENERATED_BODY()
public:
    USceneActionState_WeatherSequenceFog();
};

