#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_ConsoleRenderingVar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ConsoleRenderingVar : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_ConsoleRenderingVar();
};

