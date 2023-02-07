#pragma once
#include "CoreMinimal.h"
#include "ETimeRigInitializingBehavior.h"
#include "InitializeSceneRigActor.h"
#include "InitializeCustomActorSceneRigActor.generated.h"

class AActor;
class ASceneRigActor;
class UInitializeCustomActorSceneRigActor;

UCLASS(Blueprintable)
class UInitializeCustomActorSceneRigActor : public UInitializeSceneRigActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* m_CustomActor;
    
public:
    UInitializeCustomActorSceneRigActor();
    UFUNCTION(BlueprintCallable)
    static UInitializeCustomActorSceneRigActor* InitializeWithCustomActor(ASceneRigActor* SceneRigActor, AActor* CustomActor, ETimeRigInitializingBehavior InitializingBehaviorType);
    
};

