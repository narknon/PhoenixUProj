#include "GlobalLightRigModFloatCurve.h"

UGlobalLightRigModFloatCurve::UGlobalLightRigModFloatCurve() {
    this->Param = EGlobalLightRigModParam::ParamNone;
    this->Curve = NULL;
    this->ColorConversion = EGlobalLightRigModColorConversionType::None;
    this->Type = EGlobalLightRigModType::Absolute;
    this->Mode = EGlobalLightRigProbeMode::GameAndProbeCapture;
    this->bEnabled = true;
}

