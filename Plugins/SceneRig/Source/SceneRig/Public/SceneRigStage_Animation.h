#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Animation.generated.h"

class UAnimationProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Animation : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationProvider* DefaultProvider;
    
    FSceneRigStage_Animation();
};

