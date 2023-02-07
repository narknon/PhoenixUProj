#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage.h"
#include "SceneRigStage_Actor.h"
#include "SceneRigStage_Excursion.generated.h"

UCLASS(Blueprintable)
class USceneRigStage_Excursion : public USceneRigStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor InvitedGuest;
    
    USceneRigStage_Excursion();
};

