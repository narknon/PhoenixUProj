#include "SampleTextureToCurve.h"

FSampleTextureToCurve::FSampleTextureToCurve() {
    this->Type = ESampleTextureToCurveType::SampleAlongU;
    this->StartUV = 0.00f;
    this->EndUV = 0.00f;
    this->OtherCoordBase = 0.00f;
    this->CurveStartT = 0.00f;
    this->CurveEndT = 0.00f;
    this->ColorNormalize = ESampleTextureToColorNormalizeMode::Intensity;
    this->CurveNormalize = ESampleTextureToColorNormalizeMode::Intensity;
    this->Desaturate = 0.00f;
    this->QuantizeColorsBits = 0;
    this->ColorScale = 0.00f;
    this->AlphaChannel = ESampleTextureToCurveAlphaChannel::TextureAlpha;
    this->FixedAlpha = 0.00f;
    this->AlphaIntensity = ESampleTextureToColorNormalizeMode::Intensity;
    this->AlphaScale = 0.00f;
    this->CurveErrorTolerancePercent = 0.00f;
    this->bCubicKeys = false;
    this->bUseCurveErrorTolerance = false;
    this->bUseColorNormalize = false;
    this->bUseCurveNormalize = false;
    this->bUseDesaturate = false;
    this->bUseQuantizeColors = false;
    this->bUseColorScale = false;
    this->bDoAlpha = false;
    this->bOverrideAlphaIntensity = false;
    this->bUseAlphaScale = false;
}

