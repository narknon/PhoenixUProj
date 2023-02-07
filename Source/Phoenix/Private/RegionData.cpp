#include "RegionData.h"

URegionData::URegionData() {
    this->IsUnlocked = false;
    this->IsNewlyUnlocked = false;
    this->SplineActor = NULL;
    this->CurrentAlphaValue = 0.00f;
    this->FadeTime = 0.50f;
}

