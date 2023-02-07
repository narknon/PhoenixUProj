#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_LightCullingDisable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_LightCullingDisable : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_LightCullingDisable();
};

