#include "MapHogwartsCamera.h"

void AMapHogwartsCamera::UpdateCamera() {
}

AMapHogwartsCamera::AMapHogwartsCamera() {
    this->RotateCenterTarget = NULL;
    this->AllowRotation = false;
    this->AllowZoom = true;
    this->YawSpeed = 120.00f;
    this->MouseSensitivity = 0.05f;
    this->MaxMouseDragYawSpeed = 240.00f;
    this->YawAcceleration = 360.00f;
    this->YawDeceleration = 540.00f;
    this->MouseDragYawAcceleration = 1080.00f;
    this->MouseFlickYawDeceleration = 180.00f;
    this->ZoomAmount = 0.25f;
    this->Zoom = 0.00f;
    this->ZoomSpeed = 3.00f;
    this->MinZoomAppliedWithInput = 0.22f;
    this->ZoomAcceleration = 20.00f;
    this->ZoomDeceleration = 30.00f;
    this->AllowInitialCircleMove = true;
}

