#include "FiniteSpellTool.h"

AFiniteSpellTool::AFiniteSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FiniteLevel = 3;
    this->bRemoveSpellsFromOtherCasters = true;
    this->bRemoveBuffs = true;
}

