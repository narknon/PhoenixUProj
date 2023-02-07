#include "IKDriver_FloorContactControl.h"

FIKDriver_FloorContactControl::FIKDriver_FloorContactControl() {
    this->RampInHeight = 0.00f;
    this->RampOutHeight = 0.00f;
    this->TranslationInterpRate = 0.00f;
    this->RotationInterpRate = 0.00f;
    this->FixupHeight = 0.00f;
    this->Shape = FCEShape::Line;
    this->DrawDebug = false;
    this->UseCustomScale = false;
    this->CustomRayTraceStartScale = 0.00f;
    this->CustomRayTraceFinishScale = 0.00f;
    this->bUseFKOrientation = false;
    this->MeshOffset = 0.00f;
    this->Alpha = 0.00f;
}

