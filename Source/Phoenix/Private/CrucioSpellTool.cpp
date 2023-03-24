#include "CrucioSpellTool.h"

ACrucioSpellTool::ACrucioSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TalentProjectileDistance = 2000.00f;
    this->TalentProjectileIgnoreNearDistance = 100.00f;
    this->TalentProjectileDamage = 0.00f;
    this->TalentProjectileRandomHalfAngle = 90.00f;
    this->TalentProjectileMunition = NULL;
}

