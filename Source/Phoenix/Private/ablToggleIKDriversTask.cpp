#include "ablToggleIKDriversTask.h"

UablToggleIKDriversTask::UablToggleIKDriversTask() {
    this->IKPriority = EStandardManagedPriority::AblAbility;
    this->bEnableIK = false;
    this->bEnableFloorContact = false;
    this->bEnableLookat = false;
    this->bEnablePoseFixup = true;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
}

