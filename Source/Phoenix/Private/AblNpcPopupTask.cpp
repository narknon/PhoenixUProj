#include "AblNpcPopupTask.h"

UAblNpcPopupTask::UAblNpcPopupTask() {
    this->PopupDirection = EAblNpcPopupDirection::Forward;
    this->bUseMagnitudeAndAngle = true;
    this->Magnitude = 0.00f;
    this->MagnitudeVariance = 0.00f;
    this->Angle = 0.00f;
    this->AngleVariance = 0.00f;
    this->MagnitudeHorz = 0.00f;
    this->MagnitudeVert = 0.00f;
    this->HorizontalDamping = 0.10f;
    this->CollisionVsFloorInitialDamping = 0.70f;
    this->CollisionVsFloorDamping = 2.00f;
    this->bUseNpcMaxHeight = false;
    this->bOverrideMaxHeight = false;
    this->MaxHeightOverride = 100.00f;
    this->bModifyGravityAtTaskStart = false;
    this->GravityScaleAtTaskStart = 1.00f;
    this->bModifyGravityAtMaxHeight = false;
    this->GravityScaleAtMaxHeight = 1.00f;
    this->bModifyGravityAtApex = false;
    this->GravityScaleAtApex = 1.00f;
    this->bRestoreGravityScaleAtTaskEnd = true;
    this->bStompVelocityAtTaskStart = true;
    this->bStompVelocityAtTaskEnd = false;
    this->bIgnoreInAirCollisions = false;
    this->MovementMode = MOVE_Falling;
}

