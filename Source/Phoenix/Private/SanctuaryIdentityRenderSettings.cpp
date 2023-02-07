#include "SanctuaryIdentityRenderSettings.h"

FSanctuaryIdentityRenderSettings::FSanctuaryIdentityRenderSettings() {
    this->bOverride_Exposure = false;
    this->bOverride_ColorGrading = false;
    this->bOverride_Film = false;
    this->bOverride_LensFX = false;
    this->bOverride_Bloom = false;
    this->bOverride_MotionBlur = false;
    this->bOverride_DepthOfField = false;
    this->bOverride_Ambient = false;
    this->bOverride_ScreenSpaceReflections = false;
    this->bOverride_EmissiveAdaptation = false;
    this->bOverride_ExposureTweak = false;
    this->bOverride_DistanceFog = false;
    this->bOverride_CharacterLightRigAdjustments = false;
    this->ExposureTweak = 0.00f;
}

