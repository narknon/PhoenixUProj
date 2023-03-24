#include "AOESpellTool.h"

AAOESpellTool::AAOESpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bTargetCharacter = true;
    this->bTargetObject = true;
    this->bPlayOnGround = true;
    this->NoTargetDistance = 500.00f;
    this->AOEMunition = NULL;
}

