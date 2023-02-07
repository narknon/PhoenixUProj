#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_TransformReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_TransformReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_TransformReference();
};

