#include "BTT_Camera_Reset.h"

UBTT_Camera_Reset::UBTT_Camera_Reset() {
    this->ResetDuration = 0.50f;
    this->ResetCurve = NULL;
    this->bCancelResetOnInput = true;
    this->bSkipResetOnMouseInput = false;
    this->bResetYaw = true;
    this->bResetPitch = true;
    this->bResetToPitchFoundOnStack = true;
    this->PitchToResetTo = 0.00f;
}

