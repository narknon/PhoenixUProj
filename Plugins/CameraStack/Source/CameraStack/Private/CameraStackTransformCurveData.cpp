#include "CameraStackTransformCurveData.h"
#include "Curves/CurveFloat.h"
#include "Curves/CurveVector.h"

UCameraStackTransformCurveData::UCameraStackTransformCurveData() {
    this->CameraLocationCurve = CreateDefaultSubobject<UCurveVector>(TEXT("CameraLocationCurve"));
    this->FocalPointCurve = CreateDefaultSubobject<UCurveVector>(TEXT("FocalPointCurve"));
    this->InversePitchCurve = CreateDefaultSubobject<UCurveFloat>(TEXT("InversePitchCurve"));
}

