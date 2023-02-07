#include "ObjectScalingData.h"

UObjectScalingData::UObjectScalingData() {
    this->bGrowable = true;
    this->bShrinkable = true;
    this->CurveScaleLarger = NULL;
    this->CurveScaleLargerOffset = NULL;
    this->CurveScaleLargerRotation = NULL;
    this->RestoreCurveScaleLarger = NULL;
    this->RestoreCurveScaleLargerOffset = NULL;
    this->RestoreCurveScaleLargerRotation = NULL;
    this->CurveScaleSmaller = NULL;
    this->CurveScaleSmallerOffset = NULL;
    this->CurveScaleSmallerRotation = NULL;
    this->RestoreCurveScaleSmaller = NULL;
    this->RestoreCurveScaleSmallerOffset = NULL;
    this->RestoreCurveScaleSmallerRotation = NULL;
}

