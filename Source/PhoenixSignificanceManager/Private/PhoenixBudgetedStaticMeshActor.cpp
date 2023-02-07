#include "PhoenixBudgetedStaticMeshActor.h"

APhoenixBudgetedStaticMeshActor::APhoenixBudgetedStaticMeshActor() {
    this->DefaultSignificanceBias = ESignificanceBiasEnum::SIGNIFICANCE_BIAS_DEFAULT;
    this->bAllowRegistrationWithSignificanceManager = false;
}

