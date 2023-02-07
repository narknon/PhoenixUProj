#include "AblAddLinearImpulseTask.h"

UAblAddLinearImpulseTask::UAblAddLinearImpulseTask() {
    this->ImpulseDamping = 0.10f;
    this->ImpulseStrengthMin = 1.00f;
    this->ImpulseStrengthMax = 1.00f;
    this->DirectionType = EAblAddLinearImpulseDirectionType::Local;
}

