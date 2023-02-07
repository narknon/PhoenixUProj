#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Float.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Float : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* DefaultProvider;
    
    FSceneRigStage_Float();
};

