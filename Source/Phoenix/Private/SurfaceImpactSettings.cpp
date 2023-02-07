#include "SurfaceImpactSettings.h"

USurfaceImpactSettings::USurfaceImpactSettings() {
    this->VfxLandscapeLayerInfoWetnessOverrideThreshold = 0.52f;
    this->SfxLandscapeLayerInfoWetnessOverrideThreshold = 0.52f;
    this->ImpactLandscapeLayerInfoWetnessOverrideThreshold = 0.52f;
    this->LandscapeWetnessLayerInfo.AddDefaulted(2);
}

