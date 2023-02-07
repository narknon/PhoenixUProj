#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_CurrentCamera.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_CurrentCamera : public UTransformProvider {
    GENERATED_BODY()
public:
    UTransform_CurrentCamera();
};

