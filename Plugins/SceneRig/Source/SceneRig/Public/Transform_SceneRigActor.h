#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_SceneRigActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UTransform_SceneRigActor : public UTransformProvider {
    GENERATED_BODY()
public:
    UTransform_SceneRigActor();
};

