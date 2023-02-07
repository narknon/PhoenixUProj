#include "SceneAction_WalkToPoint.h"

USceneAction_WalkToPoint::USceneAction_WalkToPoint() {
    this->WorldSpaceTransform = NULL;
    this->bForceTravelSpeed = true;
    this->TravelSpeed = EPerformTaskSpeedMode::Walk;
    this->ArrivalRadius = 50.00f;
    this->FinishAction = EPerformTaskFinishAction::StopAndWait;
}

