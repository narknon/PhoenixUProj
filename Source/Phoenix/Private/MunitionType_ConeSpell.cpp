#include "MunitionType_ConeSpell.h"

class ASpellTool;


ASpellTool* AMunitionType_ConeSpell::GetSpellTool() const {
    return NULL;
}

AMunitionType_ConeSpell::AMunitionType_ConeSpell(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EndRadius = 100.00f;
    this->DamageType = NULL;
    this->StopAtCollision = true;
    this->ExplosionVFX = NULL;
    this->ExplosionSfx = NULL;
    this->SpellTool = NULL;
}

