#pragma once
#include "CoreMinimal.h"
#include "SceneAction_StencilFXGroups.h"
#include "SceneAction_StencilFXEnableGroups.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_StencilFXEnableGroups : public USceneAction_StencilFXGroups {
    GENERATED_BODY()
public:
    USceneAction_StencilFXEnableGroups();
};

