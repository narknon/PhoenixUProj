#include "DepulsoSpellTool.h"

ADepulsoSpellTool::ADepulsoSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetHalfAngleXY = 15;
    this->TargetHalfAngleZ = 45;
    this->LaunchAngle = 12.00f;
    this->InAirLaunchAngle = 0.00f;
    this->MaximumLaunchAngle = 30.00f;
    this->HeightAdjustment = 0.00f;
    this->LevelMinZThreshold = -150.00f;
    this->LevelMaxZThreshold = 0.00f;
    this->BasePhysicsImpulse = 0.00f;
    this->MassScaledPhysicsImpulse = 2000.00f;
    this->CharacterBasePhysicsImpulse = 0.00f;
    this->CharacterMassScaledPhysicsImpulse = 2000.00f;
    this->MaxVelocity = 2500.00f;
    this->NonMovableDamage = 0.00f;
    this->NonMovableAdditionalForce = 1000.00f;
    this->TargetingPercent = 100;
    this->bUpdateTarget = true;
    this->LeviosoImpulseScale = 1.00f;
    this->MinDamageDealt = -1.00f;
    this->MaxDamageDealt = -1.00f;
    this->MinDamageDealtCharacter = -1.00f;
    this->MaxDamageDealtCharacter = -1.00f;
    this->MinDamageTaken = -1.00f;
    this->MaxDamageTaken = -1.00f;
    this->MinDamageTakenCharacter = -1.00f;
    this->MaxDamageTakenCharacter = -1.00f;
    this->MinDamageTakenCharacterWall = -1.00f;
    this->MaxDamageTakenCharacterWall = -1.00f;
    this->MinDamageTakenCharacterFloor = -1.00f;
    this->MaxDamageTakenCharacterFloor = -1.00f;
    this->MinDamageTakenCharacterCharacter = -1.00f;
    this->MaxDamageTakenCharacterCharacter = -1.00f;
    this->AOEMunition = NULL;
}

