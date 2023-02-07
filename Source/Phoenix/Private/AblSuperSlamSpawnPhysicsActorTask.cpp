#include "AblSuperSlamSpawnPhysicsActorTask.h"

UAblSuperSlamSpawnPhysicsActorTask::UAblSuperSlamSpawnPhysicsActorTask() {
    this->MinNumberOfItems = 1;
    this->MaxNumberOfItems = 1;
    this->ConeAngle = 45.00f;
    this->MinForce = 50.00f;
    this->MaxForce = 500.00f;
    this->MinAngularForce = 50.00f;
    this->MaxAngularForce = 500.00f;
}

