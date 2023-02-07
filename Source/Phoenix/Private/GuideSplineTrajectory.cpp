#include "GuideSplineTrajectory.h"

FGuideSplineTrajectory::FGuideSplineTrajectory() {
    this->TargetPositionSpeed = 0.00f;
    this->SimDT = 0.00f;
    this->TargetHalfLife = 0.00f;
    this->TrajectoryHalfLife = 0.00f;
    this->TrajectoryDampingFactor = 0.00f;
    this->TrajectorySpeed = 0.00f;
    this->TrajectorySpeedInitialAccelerationHalfLife = 0.00f;
    this->TrajectorySpeedFinalDecelerationHalfLife = 0.00f;
    this->StartingBurstTime = 0.00f;
    this->StartingBurstTrajectorySpeed = 0.00f;
    this->ResimulationMergeDistanceThreshold = 0.00f;
}

