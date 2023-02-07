#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_AnimationReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_AnimationReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_AnimationReference();
};

