#include "AIPerformTaskRunSceneRig.h"

UAIPerformTaskRunSceneRig::UAIPerformTaskRunSceneRig() {
    this->SceneRigActor = NULL;
    this->bOrientToPlayer = false;
    this->CurrentTaskSetting = EPerformTaskSceneRigSetting::Play;
}

