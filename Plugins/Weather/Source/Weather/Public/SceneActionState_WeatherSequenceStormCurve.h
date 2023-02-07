#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceStormCurve.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceStormCurve : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    USceneActionState_WeatherSequenceStormCurve();
};

