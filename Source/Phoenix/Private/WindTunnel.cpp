#include "WindTunnel.h"

void AWindTunnel::StopDoor() {
}

void AWindTunnel::OpenDoor() {
}

void AWindTunnel::CloseDoor() {
}

void AWindTunnel::ApplyWind() {
}

AWindTunnel::AWindTunnel() {
    this->WindStrength_Objects = 4000.00f;
    this->WindStrength_Pawns = 1200.00f;
    this->WindDist = 2000.00f;
    this->DoorOpenAngle = 120.00f;
    this->DoorOpenTime = 2.00f;
    this->DoorCloseTime = 2.00f;
    this->DoorOpenSpeed = 3.00f;
    this->DoorCloseSpeed = 3.00f;
    this->StartDelay = 1.00f;
    this->TunnelTraceVisibility = EDrawDebugTrace::None;
    this->ObjectTraceVisibility = EDrawDebugTrace::None;
    this->bDoorPauseTimeOverride = true;
    this->DoorPauseTime = 5.00f;
    this->RightDoor = NULL;
    this->LeftDoor = NULL;
    this->Arrow = NULL;
    this->RaytraceRadius = 0.00f;
    this->DoorAngle = 0.00f;
}

