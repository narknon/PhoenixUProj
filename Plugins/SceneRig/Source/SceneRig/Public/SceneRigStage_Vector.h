#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Vector.generated.h"

class UVectorProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Vector : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVectorProvider* DefaultProvider;
    
    FSceneRigStage_Vector();
};

