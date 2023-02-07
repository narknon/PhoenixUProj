#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequence.h"
#include "SceneAction_WeatherSequenceCloudsPreset.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceCloudsPreset : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    USceneAction_WeatherSequenceCloudsPreset();
};

