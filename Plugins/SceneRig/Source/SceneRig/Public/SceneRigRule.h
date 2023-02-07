#pragma once
#include "CoreMinimal.h"
#include "TimeRigRule.h"
#include "SceneRigRule.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class SCENERIG_API USceneRigRule : public UTimeRigRule {
    GENERATED_BODY()
public:
    USceneRigRule();
};

