#include "BossFightData.h"

FBossFightData::FBossFightData() {
    this->BossFightState = EBossStates::BS_None;
    this->StartTime = 0.00f;
    this->EndTime = 0.00f;
    this->ElapsedTime = 0.00f;
    this->BossFightStarted = false;
}

