#include "XPMeterBase.h"

bool UXPMeterBase::TryStackNotification(FExperienceChange XPChangeData) {
    return false;
}

void UXPMeterBase::StartAddingXP(float FillDuration, float StartTime) {
}

void UXPMeterBase::RemoveFromNotificationQueue() {
}





void UXPMeterBase::AddXP() {
}

UXPMeterBase::UXPMeterBase() {
    this->ActiveNotificationStackable = false;
    this->MaxFillTime = 0.00f;
    this->CurrentFillTime = 0.00f;
    this->IsFilling = false;
}

