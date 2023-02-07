#include "ablDragonMobilityTask.h"

UablDragonMobilityTask::UablDragonMobilityTask() {
    this->MobilityType = EablEnemy_DragonMobilityType::Hover;
    this->DistFromTarget = 1000.00f;
    this->HeightAboveTarget = 50.00f;
    this->MoveSpeed = 300.00f;
}

