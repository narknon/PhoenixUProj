#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "EPerformTaskFinishAction.h"
#include "EPerformTaskSpeedMode.h"
#include "SceneAction_WalkToStation.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WalkToStation : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* StationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceTravelSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskSpeedMode TravelSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskFinishAction FinishAction;
    
    USceneAction_WalkToStation();
};

