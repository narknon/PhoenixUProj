#include "LightParameterSmoothing.h"

ULightParameterSmoothing::ULightParameterSmoothing() {
    this->TimeSource = ELightParameterSmoothingTimeSource::TimeOfDay;
    this->TimeBase = ELightParameterSmoothingTimeBase::Hours;
    this->TimeBlendCurve = NULL;
    this->TimeBlendCurveInput = ELightParameterTimeBlendInput::TimeOfDay;
    this->bEnabled = true;
}

