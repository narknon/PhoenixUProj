#include "SceneAction_WeatherSequenceWindMulti.h"

USceneAction_WeatherSequenceWindMulti::USceneAction_WeatherSequenceWindMulti() {
    this->BlendInTime = 2.00f;
    this->BlendInTimeBase = EWindParametersTimeBase::GameMinutes;
    this->bRandomizeOrder = true;
}

