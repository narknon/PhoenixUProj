#include "RenderSettingsPostProcessingGroup.h"

FRenderSettingsPostProcessingGroup::FRenderSettingsPostProcessingGroup() {
    this->bOverride_Exposure = false;
    this->bOverride_ColorGrading = false;
    this->bOverride_Film = false;
    this->bOverride_LensFX = false;
    this->bOverride_Bloom = false;
    this->bOverride_MotionBlur = false;
    this->bOverride_DepthOfField = false;
    this->bOverride_Ambient = false;
    this->bOverride_ScreenSpaceReflections = false;
    this->bOverride_Probes = false;
}

