#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_String.generated.h"

class UStringProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_String : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStringProvider* DefaultProvider;
    
    FSceneRigStage_String();
};

