#include "DepulsoMaximaSpellTool.h"

ADepulsoMaximaSpellTool::ADepulsoMaximaSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShowDebug = false;
    this->BasePhysicsImpulse = 0.00f;
    this->MassScaledPhysicsImpulse = 2000.00f;
    this->CharacterBasePhysicsImpulse = 0.00f;
    this->CharacterMassScaledPhysicsImpulse = 2000.00f;
    this->MaxVelocity = 2500.00f;
    this->TargetHalfAngleXY = 15;
    this->TargetHalfAngleZ = 45;
    this->LaunchAngle = 12.00f;
    this->HeightAdjustment = 0.00f;
    this->LevelMinZThreshold = -150.00f;
    this->LevelMaxZThreshold = 0.00f;
    this->TargetingPercent = 100;
    this->bUpdateTarget = true;
    this->LeviosoImpulseScale = 1.00f;
    this->NonMovableDamageMax = 75.00f;
    this->NonMovableDamageMin = 25.00f;
    this->NonMovableAdditionalForce = 1000.00f;
}

