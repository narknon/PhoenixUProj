#include "Enemy_MobilityData.h"

FEnemy_MobilityData::FEnemy_MobilityData() {
    this->SpeedMin = 0.00f;
    this->SpeedMax = 0.00f;
    this->MoveDistThreshold = 0.00f;
    this->MobilityModeState = EMobilityModeState::Invalid;
}

