#include "GlobalLightRigModFloatCurveNew.h"

UGlobalLightRigModFloatCurveNew::UGlobalLightRigModFloatCurveNew() {
    this->Param = EGlobalLightRigModParam::ParamNone;
    this->Curve = NULL;
    this->ColorConversion = EGlobalLightRigModColorConversionType::None;
}

