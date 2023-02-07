#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_IntValue.generated.h"

class UIntProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_IntValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIntProvider* Provider;
    
    USceneRigStage_IntValue();
};

