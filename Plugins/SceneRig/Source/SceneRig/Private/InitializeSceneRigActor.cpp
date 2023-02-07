#include "InitializeSceneRigActor.h"

class ASceneRigActor;
class UInitializeSceneRigActor;

UInitializeSceneRigActor* UInitializeSceneRigActor::Initialize(ASceneRigActor* SceneRigActor, ETimeRigInitializingBehavior InitializingBehaviorType) {
    return NULL;
}

UInitializeSceneRigActor::UInitializeSceneRigActor() {
    this->m_SceneRigActor = NULL;
    this->m_InitializingBehaviorType = ETimeRigInitializingBehavior::None;
}

