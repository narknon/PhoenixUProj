#include "GlobalLightingBlendableProbeLighting.h"

UGlobalLightingBlendableProbeLighting::UGlobalLightingBlendableProbeLighting() {
    this->ProbeLightingParameters = NULL;
    this->OverrideSource = EGlobalLightingBlendableInputType::CombinedValues;
}

