#include "AnimatedLightsClusterSettings.h"

void UAnimatedLightsClusterSettings::SetRange(float NewTickEveryFrameDistanceMeters, float NewSlowTickDistanceMeters) {
}

UAnimatedLightsClusterSettings::UAnimatedLightsClusterSettings() {
    this->TickEveryFrameDistanceMeters = 30.00f;
    this->SlowTickDistanceMeters = 60.00f;
    this->SlowTickRateSeconds = 0.67f;
    this->MaxTickEveryFrameDistanceMeters = 75.00f;
    this->MaxSlowTickDistanceMeters = 125.00f;
    this->InverseRange = 0.03f;
    this->MaxInverseRange = 0.02f;
    this->SlowTickInverseRange = 0.02f;
    this->bAutoScale = false;
}

