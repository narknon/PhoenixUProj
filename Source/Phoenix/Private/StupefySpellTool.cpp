#include "StupefySpellTool.h"

AStupefySpellTool::AStupefySpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AOEMunition = NULL;
    this->CharacterDurationScaleTalent = 2.00f;
    this->CharacterDamageTalent = 10.00f;
    this->KillAuthorityFigure = false;
    this->UpgradedMunitionActor = NULL;
}

