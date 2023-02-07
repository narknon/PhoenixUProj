#include "SkyAtmosphereScatteringParametersOverride.h"

FSkyAtmosphereScatteringParametersOverride::FSkyAtmosphereScatteringParametersOverride() {
    this->bOverride_MultiScatteringFactor = false;
    this->bOverride_RayleighScatteringScale = false;
    this->bOverride_RayleighScattering = false;
    this->bOverride_RayleighExponentialDistribution = false;
    this->bOverride_MieScatteringScale = false;
    this->bOverride_MieScattering = false;
    this->bOverride_MieAbsorptionScale = false;
    this->bOverride_MieAbsorption = false;
    this->bOverride_MieAnisotropy = false;
    this->bOverride_MieExponentialDistribution = false;
    this->MultiScatteringFactor = 0.00f;
    this->RayleighScatteringScale = 0.00f;
    this->RayleighExponentialDistribution = 0.00f;
    this->MieScatteringScale = 0.00f;
    this->MieAbsorptionScale = 0.00f;
    this->MieAnisotropy = 0.00f;
    this->MieExponentialDistribution = 0.00f;
}

