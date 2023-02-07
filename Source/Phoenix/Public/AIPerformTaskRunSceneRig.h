#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "EPerformTaskSceneRigSetting.h"
#include "SceneRigPlayedDelegate.h"
#include "AIPerformTaskRunSceneRig.generated.h"

class ASceneRigActor;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskRunSceneRig : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASceneRigActor* SceneRigActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientToPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskSceneRigSetting CurrentTaskSetting;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigPlayed OnSceneRigPlayed;
    
    UAIPerformTaskRunSceneRig();
};

