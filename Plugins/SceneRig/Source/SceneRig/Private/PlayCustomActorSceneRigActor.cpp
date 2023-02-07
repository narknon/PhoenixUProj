#include "PlayCustomActorSceneRigActor.h"

class AActor;
class ASceneRigActor;
class UPlayCustomActorSceneRigActor;

UPlayCustomActorSceneRigActor* UPlayCustomActorSceneRigActor::PlaySceneRigWithCustomActor(ASceneRigActor* SceneRigActor, AActor* CustomActor, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

UPlayCustomActorSceneRigActor::UPlayCustomActorSceneRigActor() {
    this->m_CustomActor = NULL;
}

