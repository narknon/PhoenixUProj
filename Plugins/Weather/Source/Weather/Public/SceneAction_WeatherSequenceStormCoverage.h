#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceStormCurve.h"
#include "SceneAction_WeatherSequenceStormCoverage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceStormCoverage : public USceneAction_WeatherSequenceStormCurve {
    GENERATED_BODY()
public:
    USceneAction_WeatherSequenceStormCoverage();
};

