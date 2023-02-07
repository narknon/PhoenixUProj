#include "AdjustedValueFloat.h"

FAdjustedValueFloat::FAdjustedValueFloat() {
    this->Mode = EAdjustedValueMode::NoChange;
    this->Value = 0.00f;
    this->ClampMin = 0.00f;
    this->bClampMin = false;
    this->ClampMax = 0.00f;
    this->bClampMax = false;
    this->ValidateMin = 0.00f;
    this->ValidateMax = 0.00f;
}

