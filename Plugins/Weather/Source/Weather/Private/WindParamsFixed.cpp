#include "WindParamsFixed.h"

UWindParamsFixed::UWindParamsFixed() {
    this->Angle = 0.00f;
    this->Speed = 0.00f;
    this->WindGustController = NULL;
    this->bLoopModAngle = true;
    this->bLoopModSpeed = true;
}

