#include "ExpelliarmusSpellTool.h"

AExpelliarmusSpellTool::AExpelliarmusSpellTool() {
    this->ScaleDisarmForce = 0.30f;
    this->TalentProjectileDistance = 1000.00f;
    this->TalentProjectileIgnoreNearDistance = 100.00f;
    this->TalentProjectileDelay = 0.10f;
    this->TalentProjectileDamage = 15.00f;
    this->TalentProjectileTargetHalfAngleXY = 120;
    this->TalentProjectileMunition = NULL;
}

