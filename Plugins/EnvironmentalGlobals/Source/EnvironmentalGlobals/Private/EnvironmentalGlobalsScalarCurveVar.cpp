#include "EnvironmentalGlobalsScalarCurveVar.h"

UEnvironmentalGlobalsScalarCurveVar::UEnvironmentalGlobalsScalarCurveVar() {
    this->Curve = NULL;
    this->CurveX = EEnvironmentalGlobalsValue::DayNight;
    this->Conversion = EEnvironmentalGlobalsScalarConversion::None;
}

