#include "BlendableFogZInfo.h"

FBlendableFogZInfo::FBlendableFogZInfo() {
    this->BaseZ = 0.00f;
    this->EyeZ = 0.00f;
    this->PlayerZ = 0.00f;
    this->CurrentZ = 0.00f;
    this->bEyeZValid = false;
    this->bPlayerZValid = false;
}

