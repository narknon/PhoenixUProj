#include "MapBaseActor.h"

class AMapPawn;

void AMapBaseActor::SetMapPawn(AMapPawn* Pawn) {
}

AMapPawn* AMapBaseActor::GetMapPawn() {
    return NULL;
}

AMapBaseActor::AMapBaseActor() {
    this->ZoomFadeStart = 0.30f;
    this->ZoomFadeEnd = 0.70f;
    this->MinimumAlpha = 0.50f;
    this->MapCursorClass = NULL;
    this->MaxFrameCountToCover = 2;
    this->MapAnalogControllerMin = 0.25f;
    this->CameraParameters = NULL;
}

