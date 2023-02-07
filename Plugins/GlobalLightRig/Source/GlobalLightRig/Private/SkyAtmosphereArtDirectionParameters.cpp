#include "SkyAtmosphereArtDirectionParameters.h"

FSkyAtmosphereArtDirectionParameters::FSkyAtmosphereArtDirectionParameters() {
    this->SkyLuminanceFactorIntensity = 0.00f;
    this->SkyDesaturation = 0.00f;
    this->AerialPespectiveViewDistanceScale = 0.00f;
    this->AerialPerspectiveStartDepth = 0.00f;
    this->HeightFogContribution = 0.00f;
    this->HeightFogContributionInscattering = 0.00f;
    this->HeightFogContributionDirectionalInscaterring = 0.00f;
    this->HeightFogAccurateInscatteringColor = 0.00f;
    this->HeightFogContributionDesaturation = 0.00f;
    this->HeightFogContributionDesaturationInscattering = 0.00f;
    this->HeightFogContributionDesaturationDirectionalInscattering = 0.00f;
    this->TransmittanceMinLightElevationAngle = 0.00f;
    this->HorizonToZenithColorationTexture = NULL;
    this->HorizonToZenithColorationU = 0.00f;
    this->HorizonToZenithColorationIntensity = 0.00f;
    this->HorizonToZenithColorationDesaturation = 0.00f;
    this->HorizonToZenithFogOpticalDepthScale = 0.00f;
    this->HorizonToZenithFogOpticalDepthPower = 0.00f;
    this->HorizonToZenithFogIntensity = 0.00f;
    this->HorizonToZenithFogDesaturation = 0.00f;
}

