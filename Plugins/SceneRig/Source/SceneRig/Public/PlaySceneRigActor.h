#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ETimeRigInitializingBehavior.h"
#include "PlaySceneRigOutputPinDelegate.h"
#include "PlaySceneRigActor.generated.h"

class ASceneRigActor;
class UPlaySceneRigActor;

UCLASS(Blueprintable)
class UPlaySceneRigActor : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlaySceneRigOutputPin PlayerAssigned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlaySceneRigOutputPin PlaybackStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlaySceneRigOutputPin PlaybackComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASceneRigActor* m_SceneRigActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ETimeRigInitializingBehavior m_InitializingBehaviorType;
    
public:
    UPlaySceneRigActor();
    UFUNCTION(BlueprintCallable)
    static UPlaySceneRigActor* PlaySceneRig(ASceneRigActor* SceneRigActor, ETimeRigInitializingBehavior InitializingBehaviorType);
    
};

