#include "AblBranchConditionGaitSpeed.h"

UAblBranchConditionGaitSpeed::UAblBranchConditionGaitSpeed() {
    this->GaitSpeeds.AddDefaulted(1);
    this->SpeedType = ESpeedType::DesiredSpeed;
    this->BufferSampleTime = 0.10f;
}

