#include "MovementPredictionSettings.h"

FMovementPredictionSettings::FMovementPredictionSettings() {
    this->bEnablePrediction = false;
    this->PredictionDuration = 0.00f;
    this->MinJumpOnHeight = 0.00f;
    this->MaxJumpOnHeight = 0.00f;
    this->MinJumpDownHeight = 0.00f;
    this->JumpOverDistance = 0.00f;
    this->MaxGrazingAngle = 0.00f;
    this->DistanceBetweenProbes = 0.00f;
    this->TurnRate = 0.00f;
    this->bTimeSlice = false;
    this->bEnableLandingPrediction = false;
    this->bOnlyLandOnNavmesh = false;
    this->bWaterCollisionChannelIsSet = false;
    this->WaterCollisionChannel = ECC_WorldStatic;
    this->bDebugDelayBetweenUpdates = false;
    this->bDebugDrawTrajectory = false;
    this->bDebugDrawSensorInfo = false;
    this->SensorDrawDuration = 0.00f;
    this->bDebugDrawSweeps = false;
}

