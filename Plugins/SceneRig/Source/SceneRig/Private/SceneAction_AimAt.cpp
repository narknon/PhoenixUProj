#include "SceneAction_AimAt.h"

USceneAction_AimAt::USceneAction_AimAt() {
    this->AimTarget = NULL;
    this->AimAxis = EAimAtAxisType::Forward;
}

