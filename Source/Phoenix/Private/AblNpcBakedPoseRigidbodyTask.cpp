#include "AblNpcBakedPoseRigidbodyTask.h"

UAblNpcBakedPoseRigidbodyTask::UAblNpcBakedPoseRigidbodyTask() {
    this->bAttachBakedPoseOnTaskStart = true;
    this->bRemoveBakedPoseOnTaskStart = false;
    this->bAttachBakedPoseOnTaskEnd = false;
    this->bRemoveBakedPoseOnTaskEnd = true;
    this->bApplyForcesToBakedPose = false;
    this->bVelocityAwayFromInstigator = false;
}

