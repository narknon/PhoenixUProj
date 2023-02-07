#include "Creature_MountFlightDynamics.h"

UCreature_MountFlightDynamics::UCreature_MountFlightDynamics() {
    this->LiftConstant = 0.01f;
    this->DragConstantParallel = 0.00f;
    this->DragConstantPerpendicular = 0.00f;
    this->Thrust = 100.00f;
    this->LiftDeltaFromAngleCompensationVerticalWhenAscending = 1.00f;
    this->LiftDeltaFromAngleCompensationHorizontalWhenAscending = 1.00f;
    this->LiftDeltaFromAngleCompensationVerticalWhenDescending = 1.00f;
    this->LiftDeltaFromAngleCompensationHorizontalWhenDescending = 1.00f;
    this->LiftDeltaFromSpeedCompensationVertical = 1.00f;
    this->LiftDeltaFromSpeedBaseSpeed = 1000.00f;
    this->BrakingStiffness = 1.00f;
    this->MaxBrakingMagnitude = 1000.00f;
    this->MaxRollDegrees = 45.00f;
    this->MaxPitchDegreesUp = 45.00f;
    this->MaxPitchDegreesDown = 45.00f;
    this->MaxTurnRate = 1.70f;
    this->HoverGaitDragConstantParallelMultiplier = 10.00f;
    this->HoverGaitDragConstantPerpendicularMultiplier = 2.00f;
    this->HoverGaitDragBlendInTime = 1.00f;
}

