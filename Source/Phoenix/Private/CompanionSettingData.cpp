#include "CompanionSettingData.h"

FCompanionSettingData::FCompanionSettingData() {
    this->CompanionFarDistance = 0.00f;
    this->CompanionTeleportDistance = 0.00f;
    this->CompanionIdealFollowDistance = 0.00f;
    this->CompanionIdealFollowBufferDistance = 0.00f;
    this->bUsePlayerMovement = false;
    this->MovementDelay = 0.00f;
    this->BypassMovementDelayTimerDistance = 0.00f;
    this->bCanSlowWalk = false;
    this->StartSlowWalkingProximityRadius = 0.00f;
    this->bCanWalk = false;
    this->StartWalkingProximityRadius = 0.00f;
    this->bCanJog = false;
    this->StartJoggingProximityRadius = 0.00f;
    this->bCanSprint = false;
    this->StartSprintingProximityRadius = 0.00f;
    this->MaxCompanionCombatDistance = 0.00f;
    this->PlayerLowHealthPercentage = 0.00f;
    this->MaxCompanionHealingDistance = 0.00f;
    this->PlayerHealingCooldownTime = 0.00f;
    this->PlayerDownUndetectedTime = 0.00f;
    this->UseDisillusionment = false;
    this->DisillusionmentCooldownTime = 0.00f;
    this->LumosCooldownTime = 0.00f;
    this->MaximumVoiceoverRange = 0.00f;
}

