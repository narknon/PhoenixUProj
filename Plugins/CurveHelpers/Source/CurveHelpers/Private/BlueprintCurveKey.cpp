#include "BlueprintCurveKey.h"

FBlueprintCurveKey::FBlueprintCurveKey() {
    this->InterpMode = RCIM_Linear;
    this->TangentMode = RCTM_Auto;
    this->TangentWeightMode = RCTWM_WeightedNone;
    this->Time = 0.00f;
    this->Value = 0.00f;
    this->ArriveTangent = 0.00f;
    this->ArriveTangentWeight = 0.00f;
    this->LeaveTangent = 0.00f;
    this->LeaveTangentWeight = 0.00f;
}

