#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceSurfaceFog.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceSurfaceFog : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    USceneActionState_WeatherSequenceSurfaceFog();
};

