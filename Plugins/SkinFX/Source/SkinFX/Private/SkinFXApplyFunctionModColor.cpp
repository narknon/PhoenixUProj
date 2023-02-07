#include "SkinFXApplyFunctionModColor.h"

FSkinFXApplyFunctionModColor::FSkinFXApplyFunctionModColor() {
    this->Scale = 0.00f;
    this->Op = ESkinFXFunctionModOp::Add;
    this->ClampMin = 0.00f;
    this->ClampMax = 0.00f;
    this->bClampMin = false;
    this->bClampMax = false;
    this->ColorMod = ESkinFXEnvelopeColorMod::RGBONLY;
}

