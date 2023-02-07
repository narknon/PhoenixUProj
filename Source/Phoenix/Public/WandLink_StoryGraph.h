#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_Actor.h"
#include "SceneRig_StoryGraph.h"
#include "WandLink_StoryGraph.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UWandLink_StoryGraph : public USceneRig_StoryGraph {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor Antagonist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor TeleportLocation1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor TeleportLocation2;
    
    UWandLink_StoryGraph();
};

