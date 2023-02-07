#include "SceneAction_PlaySceneRig.h"

USceneAction_PlaySceneRig::USceneAction_PlaySceneRig() {
    this->SceneRigProvider = NULL;
    this->Initialize = ESceneAction_PlaySceneRigInitializeType::OnStartOfSceneRig;
}

