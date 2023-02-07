#include "RigUnit_SplineIK.h"

FRigUnit_SplineIK::FRigUnit_SplineIK() {
    this->BoneAxis = ESplineIKBoneAxis::None;
    this->bAutoCalculateSpline = false;
    this->PointCount = 0;
    this->Roll = 0.00f;
    this->TwistStart = 0.00f;
    this->TwistEnd = 0.00f;
    this->Stretch = 0.00f;
    this->Offset = 0.00f;
}

