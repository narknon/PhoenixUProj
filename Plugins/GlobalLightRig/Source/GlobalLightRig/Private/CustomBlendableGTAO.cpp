#include "CustomBlendableGTAO.h"

FCustomBlendableGTAO::FCustomBlendableGTAO() {
    this->bOverride_Enabled = false;
    this->bOverride_UseNormals = false;
    this->bOverride_FilterWidth = false;
    this->bOverride_ThicknessBlend = false;
    this->bOverride_FalloffEnd = false;
    this->bOverride_FalloffStartRatio = false;
    this->bOverride_NumAngles = false;
    this->bOverride_PauseJitter = false;
    this->bOverride_UpsampleDepthAware = false;
    this->bOverride_Downsample = false;
    this->bOverride_TemporalFilter = false;
    this->bOverride_SpatialFilter = false;
    this->bOverride_Combined = false;
    this->bEnabled = false;
    this->bUseNormals = false;
    this->FilterWidth = 0;
    this->ThicknessBlend = 0.00f;
    this->FalloffEnd = 0.00f;
    this->FalloffStartRatio = 0.00f;
    this->NumAngles = 0;
    this->PauseJitter = 0.00f;
    this->bUpsampleDepthAware = false;
    this->bDownsample = false;
    this->bTemporalFilter = false;
    this->bSpatialFilter = false;
    this->bCombined = false;
}

