#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Transform.generated.h"

class UTransformProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Transform : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* DefaultProvider;
    
    FSceneRigStage_Transform();
};

