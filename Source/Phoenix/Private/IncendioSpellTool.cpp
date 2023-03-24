#include "IncendioSpellTool.h"

AIncendioSpellTool::AIncendioSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CharacterDamageScale = 1.00f;
    this->AOEMunition = NULL;
    this->CurrentAOE = NULL;
}

