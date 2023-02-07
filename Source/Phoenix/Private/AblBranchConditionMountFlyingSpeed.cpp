#include "AblBranchConditionMountFlyingSpeed.h"

UAblBranchConditionMountFlyingSpeed::UAblBranchConditionMountFlyingSpeed() {
    this->FlyingGaits.AddDefaulted(1);
    this->SpeedType = ESpeedType::DesiredSpeed;
    this->BufferSampleTime = 0.10f;
}

