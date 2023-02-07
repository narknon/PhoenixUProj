#include "AIPerformTaskMoveToStation.h"

class UObject;

void UAIPerformTaskMoveToStation::StartStationExit() {
}

void UAIPerformTaskMoveToStation::OnStationEnterFinished(const UObject* i_caller) {
}

UAIPerformTaskMoveToStation::UAIPerformTaskMoveToStation() {
    this->TargetStation = NULL;
    this->bInteract = true;
    this->ConnectionIndex = -1;
    this->stationDuration = -1.00f;
    this->SpeedMode = EPerformTaskSpeedMode::Walk;
}

