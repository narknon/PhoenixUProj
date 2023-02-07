#include "AblHideActorTask.h"

UAblHideActorTask::UAblHideActorTask() {
    this->bHideThroughManagedState = false;
    this->bIgnoreParticleEmitters = true;
    this->bIgnoreStaticMeshes = false;
    this->bMustPassAllConditions = false;
}

