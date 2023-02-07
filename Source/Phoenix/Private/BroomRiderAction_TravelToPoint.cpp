#include "BroomRiderAction_TravelToPoint.h"

void UBroomRiderAction_TravelToPoint::CheckPlayerDistanceToNPC() {
}

UBroomRiderAction_TravelToPoint::UBroomRiderAction_TravelToPoint() {
    this->PrevBroomPhysicsData = NULL;
    this->bRestoreFlightDataOnFinish = false;
    this->bLoopUntilMessage = false;
    this->Point = 0;
    this->bKeepPlayerCloseToNPC = false;
    this->bSetStatOnPlayerLeaveNPC = false;
    this->StatValueToSet = 0;
    this->MaxDistanceFromNPC = 3500.00f;
    this->DistanceBehindNPCToResetTo = 1500.00f;
    this->BroomEnemyState = EBroomEnemyState::None;
}

