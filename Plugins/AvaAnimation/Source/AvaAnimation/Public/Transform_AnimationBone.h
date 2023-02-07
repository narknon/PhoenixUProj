#pragma once
#include "CoreMinimal.h"
#include "AnimationTransformProvider.h"
#include "Transform_AnimationBone.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_AnimationBone : public UAnimationTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UTransform_AnimationBone();
};

