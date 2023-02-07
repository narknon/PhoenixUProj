#include "CameraFixupNoiseOperation.h"

UCameraFixupNoiseOperation::UCameraFixupNoiseOperation() {
    this->DrawDebug = false;
    this->ExplicitAsset = NULL;
    this->XPositionProvider = NULL;
    this->YPositionProvider = NULL;
    this->ZPositionProvider = NULL;
    this->PitchAngleProvider = NULL;
    this->YawAngleProvider = NULL;
    this->RollAngleProvider = NULL;
}

