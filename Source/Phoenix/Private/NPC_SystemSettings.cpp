#include "NPC_SystemSettings.h"

UNPC_SystemSettings::UNPC_SystemSettings() {
    this->PlayerRelTargetProximityDist = 5000.00f;
    this->PlayerRelTargetTrackingChangeTime = 1.00f;
    this->TeleportMoveGlobalTimer = 10.00f;
    this->TeleportMoveStuckTimer = 10.00f;
    this->TooCloseCounterAttackGlobalTimer = 4.00f;
    this->TooCloseCounterAttackConsiderationTimer = 1.00f;
    this->CombatQBUpdateBudget = 0.00f;
}

