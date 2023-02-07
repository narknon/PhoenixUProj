#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigParameterDefinition_AnimationTransform.generated.h"

class UAnimationTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameterDefinition_AnimationTransform : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationTransformProvider* DefaultValue;
    
    USceneRigParameterDefinition_AnimationTransform();
};

