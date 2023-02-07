#include "RenderSettingsPPColorGrading.h"

FRenderSettingsPPColorGrading::FRenderSettingsPPColorGrading() {
    this->bOverride_WhiteTemp = false;
    this->bOverride_WhiteTint = false;
    this->bOverride_ColorCorrectionShadowsMax = false;
    this->bOverride_ColorCorrectionHighlightsMin = false;
    this->bOverride_SceneColorTint = false;
    this->bOverride_BlueCorrection = false;
    this->bOverride_ExpandGamut = false;
    this->WhiteTemp = 0.00f;
    this->WhiteTint = 0.00f;
    this->ColorCorrectionShadowsMax = 0.00f;
    this->ColorCorrectionHighlightsMin = 0.00f;
    this->BlueCorrection = 0.00f;
    this->ExpandGamut = 0.00f;
}

