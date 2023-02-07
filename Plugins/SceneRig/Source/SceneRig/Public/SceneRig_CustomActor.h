#pragma once
#include "CoreMinimal.h"
#include "SceneRig.h"
#include "SceneRigStage_Actor.h"
#include "SceneRig_CustomActor.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRig_CustomActor : public USceneRig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor CustomActor;
    
    USceneRig_CustomActor();
};

