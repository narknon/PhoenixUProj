#include "AdjustedValueInt.h"

FAdjustedValueInt::FAdjustedValueInt() {
    this->Mode = EAdjustedValueMode::NoChange;
    this->Value = 0;
    this->ClampMin = 0;
    this->bClampMin = false;
    this->ClampMax = 0;
    this->bClampMax = false;
    this->ValidateMin = 0;
    this->ValidateMax = 0;
}

