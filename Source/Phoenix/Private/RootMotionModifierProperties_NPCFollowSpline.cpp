#include "RootMotionModifierProperties_NPCFollowSpline.h"

URootMotionModifierProperties_NPCFollowSpline::URootMotionModifierProperties_NPCFollowSpline() {
    this->StartSpeed = 450.00f;
    this->bUseActualSpeedAsStartSpeed = true;
    this->Acceleration = 200.00f;
    this->MinSpeed = 200.00f;
    this->MaxSpeed = 1000.00f;
    this->RotationSpeed = 720.00f;
    this->MaxOffsetRadius = 200.00f;
    this->HoritzontalSpeed = 200.00f;
    this->bDebug = false;
}

