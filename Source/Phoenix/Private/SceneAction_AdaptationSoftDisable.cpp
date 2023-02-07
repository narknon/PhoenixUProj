#include "SceneAction_AdaptationSoftDisable.h"

USceneAction_AdaptationSoftDisable::USceneAction_AdaptationSoftDisable() {
    this->Affects = 3;
    this->Method = ESceneActionAdaptationSoftDisableMethod::MinExposure;
    this->bIncludeBias = true;
}

