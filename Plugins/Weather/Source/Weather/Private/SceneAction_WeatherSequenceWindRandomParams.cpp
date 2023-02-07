#include "SceneAction_WeatherSequenceWindRandomParams.h"

USceneAction_WeatherSequenceWindRandomParams::USceneAction_WeatherSequenceWindRandomParams() {
    this->MinAngle = -180.00f;
    this->MaxAngle = -180.00f;
    this->MinSpeed = 2.00f;
    this->MaxSpeed = 15.00f;
    this->WindGustController = NULL;
}

