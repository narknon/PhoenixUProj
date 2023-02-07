#include "CameraFixupAimAtOperation.h"

UCameraFixupAimAtOperation::UCameraFixupAimAtOperation() {
    this->AimTarget = NULL;
    this->DrawDebug = false;
    this->HorizontalDamping = 0.00f;
    this->HorizontalDampingProvider = NULL;
    this->VerticalDamping = 0.00f;
    this->VerticalDampingProvider = NULL;
    this->ScreenX = 0.00f;
    this->ScreenXProvider = NULL;
    this->ScreenY = 0.00f;
    this->ScreenYProvider = NULL;
    this->DeadZoneWidth = 0.00f;
    this->DeadZoneWidthProvider = NULL;
    this->DeadZoneHeight = 0.00f;
    this->DeadZoneHeightProvider = NULL;
    this->SoftZoneWidth = 0.00f;
    this->SoftZoneWidthProvider = NULL;
    this->SoftZoneHeight = 0.00f;
    this->SoftZoneHeightProvider = NULL;
    this->BiasX = 0.00f;
    this->BiasXProvider = NULL;
    this->BiasY = 0.00f;
    this->BiasYProvider = NULL;
    this->CameraPositionMaxFrameDeltaProvider = NULL;
    this->AimTargetMaxFrameDeltaProvider = NULL;
}

