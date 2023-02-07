#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ActorReference.h"
#include "SceneRigStage_TransformReference.h"
#include "SceneRigStageActorPlacement.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStageActorPlacement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_ActorReference Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_TransformReference Placement;
    
    FSceneRigStageActorPlacement();
};

