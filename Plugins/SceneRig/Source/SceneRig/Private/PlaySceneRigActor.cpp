#include "PlaySceneRigActor.h"

class ASceneRigActor;
class UPlaySceneRigActor;

UPlaySceneRigActor* UPlaySceneRigActor::PlaySceneRig(ASceneRigActor* SceneRigActor, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

UPlaySceneRigActor::UPlaySceneRigActor() {
    this->m_SceneRigActor = NULL;
    this->m_InitializingBehaviorType = ETimeRigInitializingBehavior::UseSRSettings;
}

