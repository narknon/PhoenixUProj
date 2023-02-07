#include "LoopingTransformByCurveComponent.h"

ULoopingTransformByCurveComponent::ULoopingTransformByCurveComponent() {
    this->TranslateXCurve = NULL;
    this->TranslateYCurve = NULL;
    this->TranslateZCurve = NULL;
    this->RotateXCurve = NULL;
    this->RotateYCurve = NULL;
    this->RotateZCurve = NULL;
    this->ScaleXCurve = NULL;
    this->ScaleYCurve = NULL;
    this->ScaleZCurve = NULL;
    this->CurvePlayRate = 1.00f;
    this->TranslationWeight = 1.00f;
    this->RotationWeight = 1.00f;
    this->ScaleWeight = 1.00f;
}

