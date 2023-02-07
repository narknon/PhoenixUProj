#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigParameter_AnimationTransform.generated.h"

class UAnimationTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameter_AnimationTransform : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationTransformProvider* Value;
    
    USceneRigParameter_AnimationTransform();
};

