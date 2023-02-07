#include "AblRipApartTask.h"

UAblRipApartTask::UAblRipApartTask() {
    this->bReinitPose = false;
    this->MinImpulse = 100.00f;
    this->MaxImpulse = 200.00f;
    this->bSpawnActorInstead = false;
    this->LegLifetime = 30.00f;
}

