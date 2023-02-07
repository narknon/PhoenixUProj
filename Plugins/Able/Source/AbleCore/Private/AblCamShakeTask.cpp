#include "AblCamShakeTask.h"

UAblCamShakeTask::UAblCamShakeTask() {
    this->Shake = NULL;
    this->InnerRadius = 0.00f;
    this->OuterRadius = 0.00f;
    this->Falloff = 0.00f;
    this->bUseActorPositionAsEpicenter = false;
    this->bOrientShakeTowardsEpicenter = false;
    this->bPlayerOnly = false;
    this->bMustPassAllConditions = true;
}

