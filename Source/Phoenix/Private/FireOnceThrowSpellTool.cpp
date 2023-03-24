#include "FireOnceThrowSpellTool.h"

AFireOnceThrowSpellTool::AFireOnceThrowSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShowDebug = false;
    this->BasePhysicsImpulse = 0.00f;
    this->MassScaledPhysicsImpulse = 2000.00f;
    this->MaxVelocity = 10000.00f;
    this->ThrowAngleZ = 15.00f;
    this->TargetingPercent = 100.00f;
    this->TargetHalfAngleXY = 15.00f;
    this->TargetHalfAngleZ = 45.00f;
}

