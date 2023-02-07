#include "EnvironmentalGlobalsColorCurveVar.h"

UEnvironmentalGlobalsColorCurveVar::UEnvironmentalGlobalsColorCurveVar() {
    this->Curve = NULL;
    this->CurveX = EEnvironmentalGlobalsValue::DayNight;
    this->Conversion = EEnvironmentalGlobalsColorVarConversion::RGBA;
    this->Mode = EEnvironmentalGlobalsColorCurveVarMode::Normal;
}

