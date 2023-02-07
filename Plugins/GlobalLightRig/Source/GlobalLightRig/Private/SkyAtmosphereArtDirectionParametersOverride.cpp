#include "SkyAtmosphereArtDirectionParametersOverride.h"

FSkyAtmosphereArtDirectionParametersOverride::FSkyAtmosphereArtDirectionParametersOverride() {
    this->bOverride_SkyLuminanceFactor = false;
    this->bOverride_SkyLuminanceFactorIntensity = false;
    this->bOverride_SkyDesaturation = false;
    this->bOverride_AerialPespectiveViewDistanceScale = false;
    this->bOverride_AerialPerspectiveStartDepth = false;
    this->bOverride_HeightFogContribution = false;
    this->bOverride_HeightFogContributionInscattering = false;
    this->bOverride_HeightFogContributionDirectionalInscaterring = false;
    this->bOverride_HeightFogAccurateInscatteringColor = false;
    this->bOverride_HeightFogContributionDesaturation = false;
    this->bOverride_TransmittanceMinLightElevationAngle = false;
    this->bOverride_HorizonToZenithColorationTexture = false;
    this->bOverride_HorizonToZenithColorationU = false;
    this->bOverride_HorizonToZenithColorationIntensity = false;
    this->bOverride_HorizonToZenithColorationDesaturation = false;
    this->bOverride_HeightFogContributionDesaturationInscattering = false;
    this->bOverride_HeightFogContributionDesaturationDirectionalInscattering = false;
    this->bOverride_HorizonToZenithFogOpticalDepthScale = false;
    this->bOverride_HorizonToZenithFogOpticalDepthPower = false;
    this->bOverride_HorizonToZenithFogIntensity = false;
    this->bOverride_HorizonToZenithFogDesaturation = false;
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

