#include "FXUpdate_LocationRotationScale.h"

UFXUpdate_LocationRotationScale::UFXUpdate_LocationRotationScale() {
    this->InterpolationWeight = 1.00f;
    this->bUseLocationPropertyName = false;
    this->bUseOverrideLocation = false;
    this->bUseRotationPropertyName = false;
    this->bUseOverrideRotation = false;
    this->bUseScalePropertyName = false;
    this->bUseOverrideScale = false;
}

