#include "MovementSensorInfo.h"

FMovementSensorInfo::FMovementSensorInfo() {
    this->SensorType = EMovementSensorType::BlockingCollision;
    this->Time = 0.00f;
    this->TimeUntilImpact = 0.00f;
}

