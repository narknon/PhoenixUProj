#include "DamageInfo.h"

FDamageInfo::FDamageInfo() {
    this->Amount = 0.00f;
    this->bIsCritical = false;
    this->TargetActor = NULL;
    this->DestinationActor = NULL;
    this->TargetComp = NULL;
    this->Instigator = NULL;
    this->Munition = NULL;
    this->ImpactType = EImpactTypes::None;
    this->bIgnoreDamageThreshold = false;
    this->bImpactOnFire = false;
    this->bSkipImpactSound = false;
    this->bPlayerShieldBreaker = false;
    this->EnemyShieldBreaker = EEnemyShieldBreaker::None;
    this->bCursedDamage = false;
    this->bCollisionDamage = false;
    this->bDeadlyAttack = false;
    this->bFinisher = false;
    this->bAlwaysKillTarget = false;
    this->bNoReaction = false;
    this->bOnlyCalculateDamage = false;
    this->bNonLethal = false;
    this->bDOT = false;
    this->bPhysicsCollision = false;
    this->bRestoreBroken = false;
    this->bApplyEvenWhenBlocking = false;
    this->DestructionForce = 0.00f;
    this->RadialDestructionForce = 0.00f;
    this->Force = 0.00f;
    this->DestroyPieceVFXRadius = 0.00f;
    this->Duration = 0.00f;
    this->SpellTool = NULL;
    this->CharacterDamage = 0.00f;
    this->FallDamagePercent = 0.00f;
}

