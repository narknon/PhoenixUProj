#include "OppugnoLevelData.h"

FOppugnoLevelData::FOppugnoLevelData() {
    this->MassLimit = 0.00f;
    this->ObjectLimit = 0;
    this->bOnlyAffectGroup = false;
    this->OppugnoRadius = 0.00f;
    this->PullBasePhysicsImpulse = 0.00f;
    this->PullMassScaledPhysicsImpulse = 0.00f;
    this->PullMaxVelocity = 0.00f;
    this->PullTargetRadius = 0.00f;
    this->HoldBasePhysicsImpulse = 0.00f;
    this->HoldMassScaledPhysicsImpulse = 0.00f;
    this->HoldMaxVelocity = 0.00f;
    this->HoldTargetRadius = 0.00f;
    this->HoldImpulseScale = 0.00f;
    this->HoldNearDistanceScale = 0.00f;
    this->ThrowBasePhysicsImpulse = 0.00f;
    this->ThrowMassScaledPhysicsImpulse = 0.00f;
    this->ThrowMaxVelocity = 0.00f;
    this->ThrowAngle = 0.00f;
    this->TimeToPull = 0.00f;
    this->TimeToThrow = 0.00f;
    this->PullPerpendicularRotationAngle = 0.00f;
}

