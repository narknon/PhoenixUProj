#include "AblBranchConditionGaitSpeed_New.h"

UAblBranchConditionGaitSpeed_New::UAblBranchConditionGaitSpeed_New() {
    this->GaitSpeeds.AddDefaulted(1);
    this->SpeedType = ESpeedType::DesiredSpeed;
    this->BufferSampleTime = 0.10f;
}

