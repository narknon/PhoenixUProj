#include "SunDiskParameters.h"

FSunDiskParameters::FSunDiskParameters() {
    this->bAreaBasedEmissive = false;
    this->BaseSizeEmissive = 0.00f;
    this->MinEmissive = 0.00f;
    this->MaxEmissive = 0.00f;
    this->EmissiveFactor = 0.00f;
    this->DiskOnlyBrightnessModCurve = NULL;
    this->BrightnessModCurve = NULL;
    this->ColorTempCurve = NULL;
    this->ColorCurve = NULL;
    this->bManualColoration = false;
    this->bBlackBodyColorTemp = false;
    this->bNormalizeUnrealColorTemp = false;
    this->bUseColorTemp = false;
    this->bUseBrightnessMod = false;
    this->Size = 0.00f;
    this->Distance = 0.00f;
}

