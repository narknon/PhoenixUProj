#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_FloatValue.generated.h"

class UFloatProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_FloatValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Provider;
    
    USceneRigStage_FloatValue();
};

