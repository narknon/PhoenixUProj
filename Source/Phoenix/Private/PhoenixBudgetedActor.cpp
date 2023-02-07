#include "PhoenixBudgetedActor.h"

APhoenixBudgetedActor::APhoenixBudgetedActor() {
    this->DefaultSignificanceBias = ESignificanceBiasEnum::SIGNIFICANCE_BIAS_DEFAULT;
    this->bAllowRegistrationWithSignificanceManager = false;
    this->bAllowRegistrationWithLODBudgeter = false;
    this->bAllowRegistrationWithClothBudgeter = false;
}

