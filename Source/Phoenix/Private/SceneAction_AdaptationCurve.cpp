#include "SceneAction_AdaptationCurve.h"

USceneAction_AdaptationCurve::USceneAction_AdaptationCurve() {
    this->AdaptationEV100 = NULL;
    this->Affects = 3;
    this->bIncludeBias = false;
    this->bAllowOutdoorsDayTimeBoostFactor = false;
}

