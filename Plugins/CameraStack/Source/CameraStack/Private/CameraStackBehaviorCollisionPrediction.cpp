#include "CameraStackBehaviorCollisionPrediction.h"

UCameraStackBehaviorCollisionPrediction::UCameraStackBehaviorCollisionPrediction() {
    this->ForwardPredictionTime = 1.00f;
    this->ForwardPredictionStep = 0.10f;
    this->SweepCountPerUpdate = 1;
    this->SecondsBetweenSweeps = 0.00f;
    this->bCheckForEyeOverlap = true;
    this->BlendExponent = 3.00f;
    this->MinCollisionInterpSpeed = 0.00f;
    this->GridCellSize = 40.00f;
    this->GridPointThreshold = 15.00f;
    this->GridDirectionThreshold = 0.15f;
}

