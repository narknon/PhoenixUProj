#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_StageRoot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UTransform_StageRoot : public UTransformProvider {
    GENERATED_BODY()
public:
    UTransform_StageRoot();
};

