#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_AnimationTransform.generated.h"

class USceneRigParameterDefinition_AnimationTransform;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_AnimationTransform : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_AnimationTransform* Reference;
    
    FSceneRigParameterBinding_AnimationTransform();
};

