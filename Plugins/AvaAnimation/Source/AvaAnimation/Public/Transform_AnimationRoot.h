#pragma once
#include "CoreMinimal.h"
#include "AnimationTransformProvider.h"
#include "Transform_AnimationRoot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_AnimationRoot : public UAnimationTransformProvider {
    GENERATED_BODY()
public:
    UTransform_AnimationRoot();
};

