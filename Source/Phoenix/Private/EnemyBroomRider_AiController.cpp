#include "EnemyBroomRider_AiController.h"

class ACharacter;
class UFlyingBroomPhysicsScratch_Spline;

void AEnemyBroomRider_AiController::StopAndWaitForPlayer(float CriticalDistance) {
}

void AEnemyBroomRider_AiController::SetBroomYaw(float Yaw) {
}

void AEnemyBroomRider_AiController::ResumeBroom() {
}

void AEnemyBroomRider_AiController::PauseBroom() {
}

void AEnemyBroomRider_AiController::GoToPointOnSpline(int32 Point) {
}

float AEnemyBroomRider_AiController::GetDistanceFromPlayer(UFlyingBroomPhysicsScratch_Spline* SplinePhysicsScratch, ACharacter* Player) {
    return 0.0f;
}

void AEnemyBroomRider_AiController::BarrelRollRight() {
}

void AEnemyBroomRider_AiController::BarrelRollLeft() {
}

AEnemyBroomRider_AiController::AEnemyBroomRider_AiController() {
    this->BroomPhysics = NULL;
    this->BroomEnemyState = EBroomEnemyState::None;
    this->OverrideYaw = false;
    this->OwnedScheduledEntity = NULL;
}

