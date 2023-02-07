#include "SpawnedStudent.h"

FSpawnedStudent::FSpawnedStudent() {
    this->BroomSpline = NULL;
    this->PhysicsData = NULL;
    this->FlyingBroom = NULL;
    this->MaxSpeed = 0.00f;
    this->SpawnState = EBroomEnemyState::None;
    this->SpawnedFlyingBroom = NULL;
}

