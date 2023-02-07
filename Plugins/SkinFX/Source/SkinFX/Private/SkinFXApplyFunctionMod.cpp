#include "SkinFXApplyFunctionMod.h"

FSkinFXApplyFunctionMod::FSkinFXApplyFunctionMod() {
    this->Scale = 0.00f;
    this->Op = ESkinFXFunctionModOp::Add;
    this->ClampMin = 0.00f;
    this->ClampMax = 0.00f;
    this->bClampMin = false;
    this->bClampMax = false;
}

