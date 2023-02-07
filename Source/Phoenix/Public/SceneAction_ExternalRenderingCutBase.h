#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_ExternalRenderingCutBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ExternalRenderingCutBase : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_ExternalRenderingCutBase();
};

