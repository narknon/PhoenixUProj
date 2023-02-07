#pragma once
#include "CoreMinimal.h"
#include "SceneAction_StencilFXBase.h"
#include "SceneAction_StencilFXEnableInterface.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_StencilFXEnableInterface : public USceneAction_StencilFXBase {
    GENERATED_BODY()
public:
    USceneAction_StencilFXEnableInterface();
};

