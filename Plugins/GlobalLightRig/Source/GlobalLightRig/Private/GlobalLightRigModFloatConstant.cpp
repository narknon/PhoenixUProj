#include "GlobalLightRigModFloatConstant.h"

UGlobalLightRigModFloatConstant::UGlobalLightRigModFloatConstant() {
    this->Param = EGlobalLightRigModParam::ParamNone;
    this->Value = 0.00f;
    this->ColorConversion = EGlobalLightRigModColorConversionType::None;
    this->Type = EGlobalLightRigModType::Absolute;
    this->Mode = EGlobalLightRigProbeMode::GameAndProbeCapture;
    this->bEnabled = true;
}

