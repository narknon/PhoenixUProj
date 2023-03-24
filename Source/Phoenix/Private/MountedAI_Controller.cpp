#include "MountedAI_Controller.h"

class APathNode;

void AMountedAI_Controller::StartMovingToPathNode(APathNode* InPathNode) {
}

void AMountedAI_Controller::StartMoving() {
}

AMountedAI_Controller::AMountedAI_Controller(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DistanceFromGroundPathNodeThreshold = 200.00f;
    this->DistanceFromAirPathNodeThreshold = 500.00f;
    this->DistanceFromSplineThreshold = 200.00f;
    this->SplineTrackingPointHeadstartDistance = 200.00f;
    this->TicksForPredictedLocation = 10.00f;
    this->bKeepWithinDistanceOfPlayer = true;
    this->DistanceFromPlayerWaitThreshold = 4000.00f;
    this->DistanceFromPlayerSlowDownThreshold = 2000.00f;
    this->PlayerDistanceThresholdChangeDistance = 500.00f;
    this->CreatureCharacter = NULL;
    this->RiderCharacter = NULL;
    this->CreatureMountComponent = NULL;
    this->FlightMovementComponent = NULL;
    this->CreaturePathFollowingComponent = NULL;
    this->PathNode = NULL;
    this->NextPathNode = NULL;
    this->Spline = NULL;
}

