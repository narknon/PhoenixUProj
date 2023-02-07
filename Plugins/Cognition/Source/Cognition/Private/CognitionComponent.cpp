#include "CognitionComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class UAISense;

void UCognitionComponent::TimerExpired() {
}

void UCognitionComponent::SetRightStickMoving(bool bInFlag) {
}

void UCognitionComponent::SetMovementFocusDirection(const FVector& WorldDirection) {
}

void UCognitionComponent::SetLeftStickMoving(bool bInFlag) {
}

void UCognitionComponent::SetIsLocked(bool bInFlag) {
}

void UCognitionComponent::SetCameraLastMovedStick(bool InFlag) {
}

bool UCognitionComponent::IsRightStickMoving() {
    return false;
}

bool UCognitionComponent::IsLocked() {
    return false;
}

bool UCognitionComponent::IsLeftStickMoving() {
    return false;
}

bool UCognitionComponent::IsCameraLastMovedStick() {
    return false;
}

FVector UCognitionComponent::GetMovementFocusDirection() {
    return FVector{};
}

FVector2D UCognitionComponent::GetCameraFlickDirection() {
    return FVector2D{};
}

AActor* UCognitionComponent::GetBestTarget(TSubclassOf<UAISense> SenseImplementation) {
    return NULL;
}

void UCognitionComponent::DEBUG_CycleDebug() {
}

void UCognitionComponent::DEBUG_ByIndex(int32 InIndex) {
}

UCognitionComponent::UCognitionComponent() {
    this->TimeOutCameraStickMoved = 5.00f;
}

