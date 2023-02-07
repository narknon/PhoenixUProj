#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_AnimateCurves.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_AnimateCurves : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    USceneAction_AnimateCurves();
};

