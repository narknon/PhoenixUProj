#include "CameraStackBehavior.h"

class ACameraStackActor;
class UCameraStack;

void UCameraStackBehavior::SetPaused(bool bInPaused) {
}

void UCameraStackBehavior::SetDisabled(bool bInDisabled, bool bForce) {
}

bool UCameraStackBehavior::IsPaused() const {
    return false;
}

bool UCameraStackBehavior::IsDisabled() const {
    return false;
}

bool UCameraStackBehavior::IsActive() const {
    return false;
}

float UCameraStackBehavior::GetSecondsActive() const {
    return 0.0f;
}

bool UCameraStackBehavior::GetPreviousValues(FCameraData& OutData) const {
    return false;
}

ACameraStackActor* UCameraStackBehavior::GetOwner() const {
    return NULL;
}

UCameraStack* UCameraStackBehavior::GetBehaviorList() const {
    return NULL;
}

bool UCameraStackBehavior::GetAllPreviousValues(FCameraData& OutData, bool bInUseUnblendedStackValues) const {
    return false;
}

UCameraStackBehavior::UCameraStackBehavior() {
    this->DisableCounter = 0;
    this->bPaused = false;
}

