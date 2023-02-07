#include "SceneAction_EmissiveAdaptationBase.h"

USceneAction_EmissiveAdaptationBase::USceneAction_EmissiveAdaptationBase() {
    this->FeatherInTime = 0.50f;
    this->FeatherOutTime = 0.50f;
    this->Priority = 10000.00f;
    this->bEnabled = true;
}

