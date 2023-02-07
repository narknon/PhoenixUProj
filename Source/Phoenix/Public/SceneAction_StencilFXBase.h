#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_StencilFXBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_StencilFXBase : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_StencilFXBase();
};

