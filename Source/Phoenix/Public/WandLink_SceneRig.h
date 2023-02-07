#pragma once
#include "CoreMinimal.h"
#include "SceneRig.h"
#include "SceneRigStage_Actor.h"
#include "SceneRigStage_Bool.h"
#include "WandLink_SceneRig.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UWandLink_SceneRig : public USceneRig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor Antagonist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor TeleportLocation1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor TeleportLocation2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Bool Lethal;
    
    UWandLink_SceneRig();
};

