#include "SceneAction_WalkToStation.h"

USceneAction_WalkToStation::USceneAction_WalkToStation() {
    this->StationActor = NULL;
    this->bForceTravelSpeed = true;
    this->TravelSpeed = EPerformTaskSpeedMode::Walk;
    this->FinishAction = EPerformTaskFinishAction::StopAndWait;
}

