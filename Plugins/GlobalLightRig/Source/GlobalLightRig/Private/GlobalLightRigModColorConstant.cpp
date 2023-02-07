#include "GlobalLightRigModColorConstant.h"

UGlobalLightRigModColorConstant::UGlobalLightRigModColorConstant() {
    this->Param = EGlobalLightRigModParam::ParamNone;
    this->ColorType = EGlobalLightRigModLinearColorType::RGBA;
    this->Type = EGlobalLightRigModType::Absolute;
    this->Mode = EGlobalLightRigProbeMode::GameAndProbeCapture;
    this->bEnabled = true;
}

