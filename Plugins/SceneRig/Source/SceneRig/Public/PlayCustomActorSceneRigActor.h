#pragma once
#include "CoreMinimal.h"
#include "ETimeRigInitializingBehavior.h"
#include "PlaySceneRigActor.h"
#include "PlayCustomActorSceneRigActor.generated.h"

class AActor;
class ASceneRigActor;
class UPlayCustomActorSceneRigActor;

UCLASS(Blueprintable)
class UPlayCustomActorSceneRigActor : public UPlaySceneRigActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* m_CustomActor;
    
public:
    UPlayCustomActorSceneRigActor();
    UFUNCTION(BlueprintCallable)
    static UPlayCustomActorSceneRigActor* PlaySceneRigWithCustomActor(ASceneRigActor* SceneRigActor, AActor* CustomActor, ETimeRigInitializingBehavior InitializingBehaviorType);
    
};

