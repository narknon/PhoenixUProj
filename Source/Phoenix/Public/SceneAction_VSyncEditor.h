#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ConsoleRenderingVar.h"
#include "SceneAction_VSyncEditor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_VSyncEditor : public USceneAction_ConsoleRenderingVar {
    GENERATED_BODY()
public:
    USceneAction_VSyncEditor();
};

