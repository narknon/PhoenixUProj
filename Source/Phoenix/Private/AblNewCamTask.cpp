#include "AblNewCamTask.h"

UAblNewCamTask::UAblNewCamTask() {
    this->customCameraWeight = 0.00f;
    this->LookAtTarget = LookAtType::Player;
    this->alwaysLookAtTarget = false;
    this->SequentiallyPlayAllCameras = false;
    this->Disable = false;
}

