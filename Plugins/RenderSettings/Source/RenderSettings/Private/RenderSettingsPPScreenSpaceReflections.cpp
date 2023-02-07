#include "RenderSettingsPPScreenSpaceReflections.h"

FRenderSettingsPPScreenSpaceReflections::FRenderSettingsPPScreenSpaceReflections() {
    this->bOverride_Intensity = false;
    this->bOverride_Quality = false;
    this->bOverride_MaxRoughness = false;
    this->Intensity = 0.00f;
    this->Quality = 0.00f;
    this->MaxRoughness = 0.00f;
}

