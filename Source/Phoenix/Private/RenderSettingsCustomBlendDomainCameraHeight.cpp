#include "RenderSettingsCustomBlendDomainCameraHeight.h"

URenderSettingsCustomBlendDomainCameraHeight::URenderSettingsCustomBlendDomainCameraHeight() {
    this->StartHeightMeters = 20.00f;
    this->FullHeightMeters = 100.00f;
    this->Base = EWorldBaseHeightAffect::ExponentialHeightFog;
}

