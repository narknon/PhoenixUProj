#include "SceneAction_WeatherSequenceEnvGlobalScalarCurve.h"

USceneAction_WeatherSequenceEnvGlobalScalarCurve::USceneAction_WeatherSequenceEnvGlobalScalarCurve() {
    this->ClampMin = 0.00f;
    this->ClampMax = 1.00f;
    this->BlendInTime = 5.00f;
    this->bStretchToDuration = true;
    this->bClampMinValue = false;
    this->bClampMaxValue = false;
}

