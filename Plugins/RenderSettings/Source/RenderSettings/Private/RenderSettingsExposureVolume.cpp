#include "RenderSettingsExposureVolume.h"

void ARenderSettingsExposureVolume::EditExposure() {
}

ARenderSettingsExposureVolume::ARenderSettingsExposureVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ExposureTweak = 0.00f;
    this->bExposureTweak = false;
}

