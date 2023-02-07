#include "BTService_Camera_DisableInput.h"

UBTService_Camera_DisableInput::UBTService_Camera_DisableInput() {
    this->bDisableLookX = true;
    this->bDisableLookY = true;
    this->bOverrideMinDeadzone = false;
    this->MinDeadzone = 0.00f;
}

