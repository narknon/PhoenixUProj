#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage.h"
#include "SceneRigStage_Actor.h"
#include "SceneRigStage_WinnerLoser.generated.h"

UCLASS(Blueprintable)
class USceneRigStage_WinnerLoser : public USceneRigStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor Winner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor Loser;
    
    USceneRigStage_WinnerLoser();
};

