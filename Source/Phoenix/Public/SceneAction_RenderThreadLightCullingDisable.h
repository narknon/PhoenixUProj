#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ConsoleRenderingVar.h"
#include "SceneAction_RenderThreadLightCullingDisable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_RenderThreadLightCullingDisable : public USceneAction_ConsoleRenderingVar {
    GENERATED_BODY()
public:
    USceneAction_RenderThreadLightCullingDisable();
};

