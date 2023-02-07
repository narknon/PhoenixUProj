#include "AblBranchConditionVelocity_New.h"

UAblBranchConditionVelocity_New::UAblBranchConditionVelocity_New() {
    this->bSpeedIsGreaterThan = false;
    this->SpeedIsGreaterThan = 0.00f;
    this->bSpeedIsLessThan = false;
    this->SpeedIsLessThan = 1.00f;
    this->bZIsGreaterThan = false;
    this->ZIsGreaterThan = 0.00f;
    this->bZIsLessThan = false;
    this->ZIsLessThan = 1.00f;
}

