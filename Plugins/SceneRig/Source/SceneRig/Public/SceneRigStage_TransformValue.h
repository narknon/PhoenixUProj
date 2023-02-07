#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_TransformValue.generated.h"

class UTransformProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_TransformValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Provider;
    
    USceneRigStage_TransformValue();
};

