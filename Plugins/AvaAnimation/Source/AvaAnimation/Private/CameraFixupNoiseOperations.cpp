#include "CameraFixupNoiseOperations.h"

UCameraFixupNoiseOperations::UCameraFixupNoiseOperations() {
    this->XPositionProvider = NULL;
    this->YPositionProvider = NULL;
    this->ZPositionProvider = NULL;
    this->PitchAngleProvider = NULL;
    this->YawAngleProvider = NULL;
    this->RollAngleProvider = NULL;
}

