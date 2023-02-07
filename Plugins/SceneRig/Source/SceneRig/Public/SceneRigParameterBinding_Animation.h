#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundParameterDefinition.h"
#include "SceneRigParameterBinding_Animation.generated.h"

class USceneRigParameterDefinition_Animation;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameterBinding_Animation : public FSceneRigBoundParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigParameterDefinition_Animation* Reference;
    
    FSceneRigParameterBinding_Animation();
};

