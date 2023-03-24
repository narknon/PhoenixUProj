#include "DiffindoSpellTool.h"

ADiffindoSpellTool::ADiffindoSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ProjectileTargetHalfAngleXY = 120;
    this->ProjectileTargetHalfAngleZ = 60;
    this->TargetObjects = false;
    this->UpgradedMunitionActor = NULL;
}

