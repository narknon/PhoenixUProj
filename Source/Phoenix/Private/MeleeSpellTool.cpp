#include "MeleeSpellTool.h"

AMeleeSpellTool::AMeleeSpellTool() {
    this->MeleeRange = 100.00f;
    this->MeleeHalfAngle = 45.00f;
    this->HitMultipleTargets = true;
    this->OnlyAffectCharacters = true;
    this->CastAtTarget = false;
}

