#include "MaterialPermuterLoadingStrategy.h"

FMaterialPermuterLoadingStrategy::FMaterialPermuterLoadingStrategy() {
    this->Type = EMaterialPermuterLoadType::Preload;
    this->Priority = EMaterialPermuterLoadingPriority::VeryLow;
    this->PurgeTime = 0.00f;
}

