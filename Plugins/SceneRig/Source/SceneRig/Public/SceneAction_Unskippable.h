#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_Unskippable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_Unskippable : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_Unskippable();
};

