#include "RenderSettingsPPChromaticAberration.h"

FRenderSettingsPPChromaticAberration::FRenderSettingsPPChromaticAberration() {
    this->bOverride_SceneFringeIntensity = false;
    this->bOverride_StartOffset = false;
    this->SceneFringeIntensity = 0.00f;
    this->StartOffset = 0.00f;
}

