#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlwaysUseDefault;
    
    FSceneRigStage_ParameterDefinition();
};

