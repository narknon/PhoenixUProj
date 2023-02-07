#include "GlobalLightRigModColorCurve.h"

UGlobalLightRigModColorCurve::UGlobalLightRigModColorCurve() {
    this->Param = EGlobalLightRigModParam::ParamNone;
    this->Curve = NULL;
    this->ColorType = EGlobalLightRigModLinearColorType::RGBA;
    this->Type = EGlobalLightRigModType::Absolute;
    this->Mode = EGlobalLightRigProbeMode::GameAndProbeCapture;
    this->bEnabled = true;
}

