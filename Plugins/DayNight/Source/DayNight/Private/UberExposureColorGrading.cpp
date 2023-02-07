#include "UberExposureColorGrading.h"

FUberExposureColorGrading::FUberExposureColorGrading() {
    this->bUseColorSaturation = false;
    this->bUseColorContrast = false;
    this->bUseColorGamma = false;
    this->bUseColorGain = false;
    this->bUseColorOffset = false;
    this->ColorSaturation = NULL;
    this->ColorContrast = NULL;
    this->ColorGamma = NULL;
    this->ColorGain = NULL;
    this->ColorOffset = NULL;
}

