#include "AblCameraStackAnimationTask.h"

UAblCameraStackAnimationTask::UAblCameraStackAnimationTask() {
    this->SelectionMethod = ECameraStackAnimationSelection::ClosestToCameraRotation;
    this->BlendInDuration = 0.50f;
    this->BlendOutDuration = 1.25f;
    this->CrossBlendTimeOverlap = 0.00f;
    this->bLazyBlendOut = false;
    this->RetargetingHeightOffset = 50.00f;
}

