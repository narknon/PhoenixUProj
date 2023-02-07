#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_VectorReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_VectorReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_VectorReference();
};

