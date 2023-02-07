#include "EmissiveAdaptationFixedOverrideComponent.h"

UEmissiveAdaptationFixedOverrideComponent::UEmissiveAdaptationFixedOverrideComponent() {
    this->AdaptationEV100 = 0.00f;
    this->Affects = 3;
    this->bIncludeBias = false;
    this->bAllowOutdoorsDayTimeBoostFactor = false;
    this->PostProcessingPriority = 9999.00f;
    this->bBlendPostProcessSettings = false;
    this->bUsePostProcessSettings = false;
}

