#include "Enemy_EnergyData.h"

FEnemy_EnergyData::FEnemy_EnergyData() {
    this->GameContext = ENPC_GameContext::None;
    this->DrainRateScale = 0.00f;
    this->Max = 0.00f;
    this->MaxDeviation = 0.00f;
    this->RefillRate = 0.00f;
    this->RefillRateScale = 0.00f;
}

