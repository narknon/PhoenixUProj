#include "RenderSettingsCustomBlendDomainLastFrameExposureRange.h"

URenderSettingsCustomBlendDomainLastFrameExposureRange::URenderSettingsCustomBlendDomainLastFrameExposureRange() {
    this->LowExposure = -5.00f;
    this->HighExposure = 5.00f;
    this->ExposureValue = ELastFrameExposureValue::FilteredAutoExposure;
}

