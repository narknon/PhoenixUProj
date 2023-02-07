#include "GlobalLightRigModColorCurveNew.h"

UGlobalLightRigModColorCurveNew::UGlobalLightRigModColorCurveNew() {
    this->Param = EGlobalLightRigModParam::ParamNone;
    this->Curve = NULL;
    this->ColorType = EGlobalLightRigModLinearColorType::RGBA;
}

