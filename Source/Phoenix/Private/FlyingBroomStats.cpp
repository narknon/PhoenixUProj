#include "FlyingBroomStats.h"

UFlyingBroomStats::UFlyingBroomStats() {
    this->BarrelRollCooldown = 0.50f;
    this->PassiveSpeedMultiplier = 1.00f;
    this->BoostSpeedMultiplier = 1.00f;
    this->MaxBoostAmount = 100.00f;
    this->TurboSpeedMultiplier = 1.00f;
    this->TurboGateBoostGain = 25.00f;
    this->TurboDecayRate = 33.30f;
    this->PostTurboBoostAmount = 100.00f;
}

