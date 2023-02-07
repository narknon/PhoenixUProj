#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_FloatReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_FloatReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_FloatReference();
};

