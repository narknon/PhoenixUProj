#include "FlyingBroomPhysics_Spline.h"

UFlyingBroomPhysics_Spline::UFlyingBroomPhysics_Spline() {
    this->SplineTravelMaxSpeed = 3000.00f;
    this->SplineTravelMinSpeed = 2000.00f;
    this->SplineTravelTurboSpeed = 5000.00f;
    this->MaxHorizontalOffset = 300.00f;
    this->HorizontalOffsetSpeed = 300.00f;
    this->BarrelRollOffset = 250.00f;
    this->MaxVerticalOffsetUp = 100.00f;
    this->MaxVerticalOffsetDown = -100.00f;
    this->VerticalOffsetSpeed = 300.00f;
    this->MaxYaw = 45.00f;
    this->YawInterpSpeed = 1.00f;
    this->YawInterpType = ECustomInterpType::EaseIn;
    this->AnimYawInterpSpeed = 1.00f;
    this->AnimYawInterpType = ECustomInterpType::EaseIn;
    this->MaxPitch = 45.00f;
    this->PitchInterpSpeed = 1.00f;
    this->PitchInterpType = ECustomInterpType::EaseIn;
    this->SplineForwardInterpSpeed = 5.00f;
    this->SplineForwardInterpType = ECustomInterpType::Constant;
    this->SplineOffsetInterpSpeed = 5.00f;
    this->SplineOffsetInterpType = ECustomInterpType::EaseIn;
    this->OrientToSplineSpeed = 360.00f;
    this->MaxAnimPitch = 25.00f;
    this->MaxAnimYaw = 10.00f;
    this->EnemyCriticalMinDistanceOffset = 600.00f;
    this->EnemyMinDistanceOffset = 800.00f;
    this->EnemyMaxDistanceOffset = 1000.00f;
    this->EnemyCriticalMaxDistanceOffset = 1300.00f;
    this->CameraInterpSpeed = 1.00f;
    this->CameraInterpType = ECustomInterpType::EaseIn;
}

