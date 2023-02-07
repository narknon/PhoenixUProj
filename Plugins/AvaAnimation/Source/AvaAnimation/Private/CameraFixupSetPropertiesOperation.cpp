#include "CameraFixupSetPropertiesOperation.h"

UCameraFixupSetPropertiesOperation::UCameraFixupSetPropertiesOperation() {
    this->SetFocusDistance = false;
    this->FocusDistance = 0.00f;
    this->FocusDistanceProvider = NULL;
    this->SetAperture = false;
    this->Aperture = 0.00f;
    this->ApertureProvider = NULL;
    this->SetFocalLength = false;
    this->FocalLength = 0.00f;
    this->FocalLengthProvider = NULL;
    this->EnableAnimatedFocusDistance = false;
}

