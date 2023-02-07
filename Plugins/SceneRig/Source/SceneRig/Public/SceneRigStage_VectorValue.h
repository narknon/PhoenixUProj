#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_VectorValue.generated.h"

class UVectorProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_VectorValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVectorProvider* Provider;
    
    USceneRigStage_VectorValue();
};

