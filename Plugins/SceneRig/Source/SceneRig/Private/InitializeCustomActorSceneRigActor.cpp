#include "InitializeCustomActorSceneRigActor.h"

class AActor;
class ASceneRigActor;
class UInitializeCustomActorSceneRigActor;

UInitializeCustomActorSceneRigActor* UInitializeCustomActorSceneRigActor::InitializeWithCustomActor(ASceneRigActor* SceneRigActor, AActor* CustomActor, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

UInitializeCustomActorSceneRigActor::UInitializeCustomActorSceneRigActor() {
    this->m_CustomActor = NULL;
}

