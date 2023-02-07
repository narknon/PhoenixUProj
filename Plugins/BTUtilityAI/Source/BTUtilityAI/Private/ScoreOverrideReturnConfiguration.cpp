#include "ScoreOverrideReturnConfiguration.h"

FScoreOverrideReturnConfiguration::FScoreOverrideReturnConfiguration() {
    this->MultiplierToReturn = EScoreOverrideReturnConfigurationType::Value_A;
    this->CustomMultiplier = 0.00f;
    this->RankToReturn = EScoreOverrideReturnConfigurationType::Value_A;
    this->CustomRank = 0.00f;
    this->BonusToReturn = EScoreOverrideReturnConfigurationType::Value_A;
    this->CustomBonus = 0.00f;
}

