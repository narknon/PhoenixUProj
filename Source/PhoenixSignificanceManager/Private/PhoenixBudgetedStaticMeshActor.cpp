#include "PhoenixBudgetedStaticMeshActor.h"

APhoenixBudgetedStaticMeshActor::APhoenixBudgetedStaticMeshActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultSignificanceBias = ESignificanceBiasEnum::SIGNIFICANCE_BIAS_DEFAULT;
    this->bAllowRegistrationWithSignificanceManager = false;
}

