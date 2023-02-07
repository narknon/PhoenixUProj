#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_IntReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_IntReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_IntReference();
};

