#pragma once
#include "CoreMinimal.h"
#include "TimeRigInterval.h"
#include "SceneRigActionBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigActionBase : public UTimeRigInterval {
    GENERATED_BODY()
public:
    USceneRigActionBase();
};

