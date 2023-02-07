#include "LightSettingsLerpControl.h"

ULightSettingsLerpControl::ULightSettingsLerpControl() {
    this->ModParam = EGlobalLightRigModParam::ParamNone;
    this->Param = ELightRigCurveParam::LightRigParamNone;
    this->bEnabled = true;
}

