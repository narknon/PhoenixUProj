#include "PhoenixBudgetedActor.h"

APhoenixBudgetedActor::APhoenixBudgetedActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultSignificanceBias = ESignificanceBiasEnum::SIGNIFICANCE_BIAS_DEFAULT;
    this->bAllowRegistrationWithSignificanceManager = false;
    this->bAllowRegistrationWithLODBudgeter = false;
    this->bAllowRegistrationWithClothBudgeter = false;
}

