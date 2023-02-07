#pragma once
#include "CoreMinimal.h"
#include "AnimationTransformProvider.h"
#include "SceneRigParameterBinding_AnimationTransform.h"
#include "AnimationTransform_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UAnimationTransform_SceneRigParameter : public UAnimationTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_AnimationTransform BoundParameter;
    
    UAnimationTransform_SceneRigParameter();
};

