#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_WeatherSequence.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequence : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_WeatherSequence();
};

