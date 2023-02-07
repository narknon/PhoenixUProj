#include "CharacterStateData.h"

FCharacterStateData::FCharacterStateData() {
    this->RagdollHitSfx = NULL;
    this->BonySkeleton = NULL;
    this->GameEventRadius = 0.00f;
    this->RegenerationRate = 0.00f;
    this->CapsuleUnderWaterPercReq = 0.00f;
    this->CapsuleUnderWaterPercReqStop = 0.00f;
    this->bOverrideTeammateAlly = false;
    this->bWillNearDeathKneel = false;
    this->bNearDeathKneelRecover = false;
    this->bNearDeathKneelExtendedOnDamage = false;
    this->DeathRecoverInvulnerableTime = 0.00f;
    this->bIsBossCharacter = false;
    this->bProtected = false;
    this->bImmuneToFinisherDeath = false;
    this->bIgnoreAllyAttacks = false;
    this->bImperiusCharTakesFullDamage = false;
    this->ImperiusInstigatorPtr = NULL;
    this->bDisplayDamage = false;
    this->CriticalHealthPercent = 0.00f;
    this->ReplicaHealthPercent = 0.00f;
    this->OverrideLootDropContainer = NULL;
}

