#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceStormCurve.h"
#include "SceneAction_WeatherSequenceStormIntensity.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceStormIntensity : public USceneAction_WeatherSequenceStormCurve {
    GENERATED_BODY()
public:
    USceneAction_WeatherSequenceStormIntensity();
};

