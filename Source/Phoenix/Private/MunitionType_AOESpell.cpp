#include "MunitionType_AOESpell.h"

class ASpellTool;


ASpellTool* AMunitionType_AOESpell::GetSpellTool() const {
    return NULL;
}

AMunitionType_AOESpell::AMunitionType_AOESpell() {
    this->m_hitVictimInterval = 10.00f;
    this->m_damageType = NULL;
    this->m_explosionFX = NULL;
    this->m_explosionSfx = NULL;
    this->PhysicsImpulse = 0.00f;
    this->bPlayAtBottomOfInstigator = false;
    this->m_stopAtCollision = true;
    this->bHitAllBrokenPieces = true;
    this->m_delayedDeathTime = 1.00f;
    this->bBreakBlockFX = true;
    this->PerceptionNoiseEventLoudness = 1.00f;
    this->PerceptionNoiseEventMaxRange = 0.00f;
    this->RadiusPercentAtTime = NULL;
    this->SpellTool = NULL;
}

