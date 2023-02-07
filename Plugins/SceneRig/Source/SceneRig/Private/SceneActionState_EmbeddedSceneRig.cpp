#include "SceneActionState_EmbeddedSceneRig.h"

class UTimeRigInstanceContext;

void USceneActionState_EmbeddedSceneRig::OnNamedEventChanged(FTimeRigCoordinate PreviousValue, FTimeRigCoordinate CurrentValue, UTimeRigInstanceContext* InContext) {
}

USceneActionState_EmbeddedSceneRig::USceneActionState_EmbeddedSceneRig() {
    this->SceneRig = NULL;
    this->InstanceContext = NULL;
}

