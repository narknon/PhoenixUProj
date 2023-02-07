#include "AblSuperSlamVelocityDampenerTask.h"

UAblSuperSlamVelocityDampenerTask::UAblSuperSlamVelocityDampenerTask() {
    this->AngularVelocityMultiplier = 0.25f;
    this->LinearVelocityMultiplier = 0.25f;
    this->AngularDamping = 0.25f;
    this->LinearDamping = 0.25f;
}

