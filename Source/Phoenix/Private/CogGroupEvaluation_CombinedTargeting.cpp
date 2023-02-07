#include "CogGroupEvaluation_CombinedTargeting.h"

UCogGroupEvaluation_CombinedTargeting::UCogGroupEvaluation_CombinedTargeting() {
    this->MaxFOVForScoringEnemies = 120.00f;
    this->MinFOVScoreForEnemies = 0.10f;
    this->MinHeightScore = 0.90f;
    this->NearDistanceBoostPctNonCombat = 50.00f;
    this->NearDistanceBoostPctCombatGamepad = 10.00f;
    this->NearDistanceBoostPctCombatMouse = 1.00f;
    this->BelowMouseCursorBoostPct = 50.00f;
    this->SpellComboBoostPct = 50.00f;
    this->StickyBoostPct = 3.00f;
}

