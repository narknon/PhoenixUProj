#include "LightSettingsModCurve.h"

ULightSettingsModCurve::ULightSettingsModCurve() {
    this->ModParam = EGlobalLightRigModParam::ParamNone;
    this->Param = ELightRigCurveParam::LightRigParamNone;
    this->Mode = ELightRigMode::GameAndProbeCapture;
    this->Type = ELightRigCurveType::Absolute;
    this->bEnabled = true;
}

