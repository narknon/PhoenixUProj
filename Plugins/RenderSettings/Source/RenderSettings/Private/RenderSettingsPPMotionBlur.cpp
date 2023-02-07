#include "RenderSettingsPPMotionBlur.h"

FRenderSettingsPPMotionBlur::FRenderSettingsPPMotionBlur() {
    this->bOverride_Amount = false;
    this->bOverride_Max = false;
    this->bOverride_PerObjectSize = false;
    this->Amount = 0.00f;
    this->Max = 0.00f;
    this->PerObjectSize = 0.00f;
}

