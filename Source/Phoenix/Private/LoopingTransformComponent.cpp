#include "LoopingTransformComponent.h"

ULoopingTransformComponent::ULoopingTransformComponent() {
    this->TranslateXFunction = ETransformFunction::NoTransformFunction;
    this->TranslateYFunction = ETransformFunction::NoTransformFunction;
    this->TranslateZFunction = ETransformFunction::NoTransformFunction;
    this->RotateXFunction = ETransformFunction::NoTransformFunction;
    this->RotateYFunction = ETransformFunction::NoTransformFunction;
    this->RotateZFunction = ETransformFunction::NoTransformFunction;
    this->ScaleXFunction = ETransformFunction::NoTransformFunction;
    this->ScaleYFunction = ETransformFunction::NoTransformFunction;
    this->ScaleZFunction = ETransformFunction::NoTransformFunction;
    this->CurvePeriod = 0.00f;
    this->CurveAmplitude = 0.00f;
    this->bApplyCurveCumulatively = false;
    this->RandomOffsetMax = 0.00f;
}

