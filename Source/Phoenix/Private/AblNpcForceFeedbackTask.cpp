#include "AblNpcForceFeedbackTask.h"

UAblNpcForceFeedbackTask::UAblNpcForceFeedbackTask() {
    this->ForceFeedbackEffect = NULL;
    this->bStopFeedbackAtTaskEnd = false;
    this->bLoop = false;
    this->bOnlyRumbleIfInstigatorIsPlayer = false;
    this->bUseAttenuation = false;
    this->bMustPassAllConditions = true;
    this->bOnlyCheckConditionsOnTaskStart = true;
}

