#include "SceneAction_CameraLookAtTarget.h"

USceneAction_CameraLookAtTarget::USceneAction_CameraLookAtTarget() {
    this->LookAtLocation = NULL;
    this->LookAtStrength = ECameraStackLookAtStrength::StrongOverTheShoulder;
    this->TriggerVolume = NULL;
}

