#include "CameraStackSecondaryTargetGetter.h"

class AActor;
class UCameraStack;

void UCameraStackSecondaryTargetGetter::Update(float DeltaSeconds) {
}

bool UCameraStackSecondaryTargetGetter::IsValid() const {
    return false;
}

bool UCameraStackSecondaryTargetGetter::HasValidData() const {
    return false;
}

FVector UCameraStackSecondaryTargetGetter::GetTargetLocation() const {
    return FVector{};
}

void UCameraStackSecondaryTargetGetter::GetTargetBoundingCylinder(FVector& OutCenterLocation, float& OutHalfHeight, float& OutRadius) const {
}

AActor* UCameraStackSecondaryTargetGetter::GetTargetActor() const {
    return NULL;
}

void UCameraStackSecondaryTargetGetter::Activate(UCameraStack* InList) {
}

UCameraStackSecondaryTargetGetter::UCameraStackSecondaryTargetGetter() {
    this->CommitTime = -1.00f;
}

