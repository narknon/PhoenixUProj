#include "RenderSettingsPPDepthOfField.h"

FRenderSettingsPPDepthOfField::FRenderSettingsPPDepthOfField() {
    this->bOverride_SensorWidth = false;
    this->bOverride_FocalDistance = false;
    this->bOverride_DepthBlurAmount = false;
    this->bOverride_DepthBlurRadius = false;
    this->bOverride_Occlusion = false;
    this->bOverride_Fstop = false;
    this->bOverride_MinFstop = false;
    this->bOverride_BladeCount = false;
    this->SensorWidth = 0.00f;
    this->FocalDistance = 0.00f;
    this->DepthBlurAmount = 0.00f;
    this->DepthBlurRadius = 0.00f;
    this->Occlusion = 0.00f;
    this->Fstop = 0.00f;
    this->MinFstop = 0.00f;
    this->BladeCount = 0;
}

