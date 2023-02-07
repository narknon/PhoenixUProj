#include "LerpVolumesScalar.h"

FLerpVolumesScalar::FLerpVolumesScalar() {
    this->Value = 0.00f;
    this->MinValue = 0.00f;
    this->MaxValue = 0.00f;
    this->bClampMinValue = false;
    this->bClampMaxValue = false;
    this->bNormalizeValue = false;
}

