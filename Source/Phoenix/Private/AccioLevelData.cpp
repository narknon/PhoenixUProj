#include "AccioLevelData.h"

FAccioLevelData::FAccioLevelData() {
    this->BasePhysicsImpulseCurve = NULL;
    this->MassScaledPhysicsImpulseCurve = NULL;
    this->InitialBasePhysicsImpulse = 0.00f;
    this->InitialMassScaledBasePhysicsImpulse = 0.00f;
    this->InitialImpulseDuration = 0.00f;
    this->CharacterBasePhysicsImpulse = 0.00f;
    this->CharacterMassScaledPhysicsImpulse = 0.00f;
    this->MaxVelocity = 0.00f;
    this->AccioCharacterKnockbackAtDistance = 0.00f;
    this->AdditionalFailedRadius = 0.00f;
    this->NonMovableDamage = 0.00f;
    this->NonMovableAdditionalForce = 0.00f;
}

