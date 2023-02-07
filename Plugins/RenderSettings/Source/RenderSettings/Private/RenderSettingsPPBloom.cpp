#include "RenderSettingsPPBloom.h"

FRenderSettingsPPBloom::FRenderSettingsPPBloom() {
    this->bOverride_Method = false;
    this->bOverride_Intensity = false;
    this->bOverride_Threshold = false;
    this->bOverride_Cross = false;
    this->bOverride_ConvolutionTexture = false;
    this->bOverride_DirtMaskIntensity = false;
    this->bOverride_DirtMaskTint = false;
    this->bOverride_DirtMask = false;
    this->Method = BM_SOG;
    this->Intensity = 0.00f;
    this->Threshold = 0.00f;
    this->Cross = 0.00f;
    this->ConvolutionTexture = NULL;
    this->DirtMask = NULL;
    this->DirtMaskIntensity = 0.00f;
}

