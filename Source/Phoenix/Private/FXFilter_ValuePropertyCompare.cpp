#include "FXFilter_ValuePropertyCompare.h"

UFXFilter_ValuePropertyCompare::UFXFilter_ValuePropertyCompare() {
    this->PropertyOwner = EMultiFXPropertyOwner::FX;
    this->Condition = EMultiFXCompare::Equal;
    this->Value = 0.00f;
    this->VectorUsage = EMultiFXVectorExtension::Size;
}

