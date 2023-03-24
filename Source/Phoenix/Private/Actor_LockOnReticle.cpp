#include "Actor_LockOnReticle.h"

void AActor_LockOnReticle::StickY(float AxisVal) {
}

void AActor_LockOnReticle::StickX(float AxisVal) {
}

bool AActor_LockOnReticle::IsLockedOn() const {
    return false;
}

ELockOnReticleType AActor_LockOnReticle::GetLockedOnType() const {
    return ELockOnReticleType::None;
}

AActor_LockOnReticle::AActor_LockOnReticle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AimModeCircleGrowRate = 2.00f;
    this->AimModeCircleShrinkRate = 1.00f;
    this->TargetingHorizontalStickAngle = 65.00f;
    this->TargetingVerticalStickAngle = 65.00f;
    this->FootprintRadius = 10.00f;
    this->StickInnerDeadZone = 0.10f;
    this->StickOuterDeadZone = 0.90f;
    this->MaxStickFlickMag = 0.70f;
    this->bFindNewTargetWhenLockonTargetLost = true;
    this->bReleaseTargetWhenLockonGoesInvalid = true;
    this->bFindNewTargetFromCenterOfScreen = false;
    this->bScaleFootprint = true;
    this->MinCameraDistance = 100.00f;
    this->MaxCameraDistance = 3000.00f;
    this->MinFootprintScale = 1.00f;
    this->MaxFootprintScale = 9.00f;
    this->LockOnToTargetSfx = NULL;
    this->FlickToTargetSfx = NULL;
    this->TargetReleasedSfx = NULL;
    this->TargetSwitchedWhenCurrentTargetLostSfx = NULL;
    this->LockOnReticleOffScreenWidgetClass = NULL;
    this->StickResetTime = 0.10f;
    this->BipedPlayerController = NULL;
}

