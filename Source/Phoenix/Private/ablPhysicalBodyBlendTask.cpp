#include "ablPhysicalBodyBlendTask.h"

UablPhysicalBodyBlendTask::UablPhysicalBodyBlendTask() {
    this->BlendInTime = 0.20f;
    this->BlendInOption = EAlphaBlendOption::Cubic;
    this->BlendOutTime = 0.20f;
    this->BlendOutOption = EAlphaBlendOption::Cubic;
    this->bContinous = true;
}

