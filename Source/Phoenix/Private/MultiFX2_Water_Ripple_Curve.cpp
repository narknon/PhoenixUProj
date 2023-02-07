#include "MultiFX2_Water_Ripple_Curve.h"

UMultiFX2_Water_Ripple_Curve::UMultiFX2_Water_Ripple_Curve() {
    this->SourceProperty = ENiagraWaterRippleCurveProperty::ImpactMass;
    this->CurveRadius = NULL;
    this->CurveIntensity = NULL;
    this->CurveDuration = NULL;
}

