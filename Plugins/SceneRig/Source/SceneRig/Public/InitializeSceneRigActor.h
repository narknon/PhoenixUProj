#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ETimeRigInitializingBehavior.h"
#include "InitializedOutputPinDelegate.h"
#include "InitializeSceneRigActor.generated.h"

class ASceneRigActor;
class UInitializeSceneRigActor;

UCLASS(Blueprintable)
class UInitializeSceneRigActor : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInitializedOutputPin Initialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInitializedOutputPin Failed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASceneRigActor* m_SceneRigActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ETimeRigInitializingBehavior m_InitializingBehaviorType;
    
public:
    UInitializeSceneRigActor();
    UFUNCTION(BlueprintCallable)
    static UInitializeSceneRigActor* Initialize(ASceneRigActor* SceneRigActor, ETimeRigInitializingBehavior InitializingBehaviorType);
    
};

