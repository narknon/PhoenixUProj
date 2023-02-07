#include "SkyAtmosphereOzoneParametersOverride.h"

FSkyAtmosphereOzoneParametersOverride::FSkyAtmosphereOzoneParametersOverride() {
    this->bOverride_OzoneAbsorptionScale = false;
    this->bOverride_OzoneAbsorption = false;
    this->bOverride_OzoneTentDistributionTipAltitude = false;
    this->bOverride_OzoneTentDistributionTipValue = false;
    this->bOverride_OzoneTentDistributionWidth = false;
    this->OzoneAbsorptionScale = 0.00f;
    this->OzoneTentDistributionTipAltitude = 0.00f;
    this->OzoneTentDistributionTipValue = 0.00f;
    this->OzoneTentDistributionWidth = 0.00f;
}

