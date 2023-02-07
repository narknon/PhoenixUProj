#include "AblForceFeedbackTask.h"

UAblForceFeedbackTask::UAblForceFeedbackTask() {
    this->ForceFeedbackEffect = NULL;
    this->bStopFeedbackAtTaskEnd = false;
    this->bLoop = false;
    this->AttenuateDistanceFromPlayerCurve = NULL;
    this->AttenuateDistanceFromCameraCurve = NULL;
    this->bPlayerOnly = false;
}

