#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_ConsoleBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ConsoleBase : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_ConsoleBase();
};

