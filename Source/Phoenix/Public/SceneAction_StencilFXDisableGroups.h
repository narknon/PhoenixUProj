#pragma once
#include "CoreMinimal.h"
#include "SceneAction_StencilFXGroups.h"
#include "SceneAction_StencilFXDisableGroups.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_StencilFXDisableGroups : public USceneAction_StencilFXGroups {
    GENERATED_BODY()
public:
    USceneAction_StencilFXDisableGroups();
};

