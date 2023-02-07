#include "GroundSwarmingDeathVolume.h"

FGroundSwarmingDeathVolume::FGroundSwarmingDeathVolume() {
    this->KillEvent = EGroundSwarmingKillEventType::None;
    this->bAutoBounds = false;
    this->AutoBoundsScaleXY = 0.00f;
    this->bTestXYOnly = false;
    this->bEnabled = false;
}

