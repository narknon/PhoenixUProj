#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_ObjectReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_ObjectReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_ObjectReference();
};

