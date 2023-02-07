#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_StringReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_StringReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_StringReference();
};

