#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterDefinition.h"
#include "SceneRigStage_Actor.generated.h"

class UActorProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_Actor : public FSceneRigStage_ParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* DefaultProvider;
    
    FSceneRigStage_Actor();
};

