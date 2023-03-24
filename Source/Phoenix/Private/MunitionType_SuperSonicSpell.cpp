#include "MunitionType_SuperSonicSpell.h"

AMunitionType_SuperSonicSpell::AMunitionType_SuperSonicSpell(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpellTool = NULL;
    this->AlwaysHit = false;
    this->IncreaseRangeBy = 0.00f;
    this->IgnoreProtego = false;
}

