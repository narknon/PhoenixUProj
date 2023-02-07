#include "AblCreatureCurrentAnimStateTask.h"

UAblCreatureCurrentAnimStateTask::UAblCreatureCurrentAnimStateTask() {
    this->CurrentStance = ECreatureStance::Standing;
    this->NextStance = ECreatureStance::Standing;
    this->CurrentGait = ECreatureMovementSpeed::Stop;
    this->NextGait = ECreatureMovementSpeed::Stop;
    this->bInIdleVariation = false;
}

