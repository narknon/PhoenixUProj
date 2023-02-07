#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.h"
#include "SceneRigStage_NameReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_NameReference : public FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    FSceneRigStage_NameReference();
};

