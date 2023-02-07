#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_WeatherGeneric.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WeatherGeneric : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_WeatherGeneric();
};

