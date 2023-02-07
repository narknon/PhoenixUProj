#include "CameraStackBehaviorShake.h"

void UCameraStackBehaviorShake::AddTrauma(float InTrauma) {
}

UCameraStackBehaviorShake::UCameraStackBehaviorShake() {
    this->TraumaDuration = 1.00f;
    this->TraumaStart = 1.00f;
    this->TraumaPow = 3.00f;
    this->RepeatTraumaDelay = 0.00f;
    this->bUsePerlinNoise = true;
    this->bMaintainSeed = false;
    this->bKeepAlive = false;
}

