#include "ConfringoSpellTool.h"

float AConfringoSpellTool::GetExplosionRadius() const {
    return 0.0f;
}


AConfringoSpellTool::AConfringoSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CharacterThrowRadius = 750.00f;
    this->TargetPhysicsImpulse = 20000.00f;
    this->BasePhysicsImpulse = 0.00f;
    this->MassScaledPhysicsImpulse = 2000.00f;
    this->BaseTorque = 0.00f;
    this->MassScaleTorque = 0.00f;
    this->CharacterBasePhysicsImpulse = 0.00f;
    this->CharacterMassScaledPhysicsImpulse = 2000.00f;
    this->CharacterBaseTorque = 0.00f;
    this->CharacterMassScaleTorque = 0.00f;
    this->ObjectTargetingPercent = 0;
    this->ObjectMaxVelocity = 10000.00f;
    this->AOECharacterDamage = 25.00f;
    this->AOEObjectDamage = 25.00f;
    this->UpgradeCharacterDamage = 150.00f;
    this->UpgradeObjectDamage = 150.00f;
    this->UpgradeCharacterThrowRadius = 1000.00f;
    this->UpgradeTargetPhysicsImpulse = 30000.00f;
    this->UpgradeBasePhysicsImpulse = 0.00f;
    this->UpgradeMassScaledPhysicsImpulse = 2000.00f;
    this->UpgradeCharacterBasePhysicsImpulse = 0.00f;
    this->UpgradeCharacterMassScaledPhysicsImpulse = 2000.00f;
    this->UpgradeObjectTargetingPercent = 0;
    this->UpgradeObjectMaxVelocity = 10000.00f;
    this->UpgradeAOECharacterDamage = 50.00f;
    this->UpgradeAOEObjectDamage = 50.00f;
    this->DamageCaster = false;
    this->bCurseTarget = false;
    this->AOEMunitionDataAsset = NULL;
    this->DecalComponent = NULL;
    this->ThrowTargetHalfAngle = 15.00f;
    this->ThrowTargetAngleZ = 15.00f;
    this->Taboo = false;
    this->ThrowMinZThreshold = -300.00f;
    this->ThrowMaxZThreshold = 30.00f;
    this->BurnRateScale = 2.00f;
    this->TalentBombardaCooldownRecovery = 1000.00f;
    this->TalentRecoveryCharacterNum = 3;
    this->TalentProjectileDistance = 1000.00f;
    this->TalentProjectileIgnoreNearDistance = 100.00f;
    this->TalentProjectileDelay = 0.10f;
    this->TalentProjectileDamage = 15.00f;
    this->TalentProjectileCount = 3;
    this->TalentProjectileTargetHalfAngleXY = 120;
    this->TalentProjectileMunition = NULL;
    this->MinDamageDealt = -1.00f;
    this->MaxDamageDealt = -1.00f;
    this->MinDamageDealtCharacter = -1.00f;
    this->MaxDamageDealtCharacter = -1.00f;
    this->MinDamageTaken = -1.00f;
    this->MaxDamageTaken = -1.00f;
    this->MinDamageTakenCharacter = -1.00f;
    this->MaxDamageTakenCharacter = -1.00f;
    this->OpportunityWindowAOEMunition = NULL;
}

