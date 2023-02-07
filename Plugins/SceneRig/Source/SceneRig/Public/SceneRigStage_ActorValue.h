#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_ActorValue.generated.h"

class UActorProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_ActorValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Provider;
    
    USceneRigStage_ActorValue();
};

