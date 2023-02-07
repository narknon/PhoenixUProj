#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_BoolReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_BoolReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_BoolReference();
};

