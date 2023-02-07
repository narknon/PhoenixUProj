#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_ActorReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_ActorReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_ActorReference();
};

