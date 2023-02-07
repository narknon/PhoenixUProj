#include "OverlapEffectsHandlerEffectDebugHitPoint.h"

UOverlapEffectsHandlerEffectDebugHitPoint::UOverlapEffectsHandlerEffectDebugHitPoint() {
    this->HitPoint = EOverlapEffectsHitPoint::Default;
    this->SphereRadius = 25.00f;
    this->SphereSegments = 16;
    this->SphereThickness = 1.00f;
    this->DurationSeconds = 1.00f;
    this->bEnabled = true;
}

