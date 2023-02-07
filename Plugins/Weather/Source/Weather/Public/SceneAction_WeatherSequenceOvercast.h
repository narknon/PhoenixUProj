#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequence.h"
#include "SceneAction_WeatherSequenceOvercast.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceOvercast : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    USceneAction_WeatherSequenceOvercast();
};

