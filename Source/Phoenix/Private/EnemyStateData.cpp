#include "EnemyStateData.h"

FEnemyStateData::FEnemyStateData() {
    this->bIgnoreDatabaseData = false;
    this->bVulnerableInAir = false;
    this->InAirVulnerabilityHeightRequirement = 0.00f;
    this->bJuggernautInCombat = false;
    this->bIsStealthAttackDisabled = false;
}

