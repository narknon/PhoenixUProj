#include "RenderSettingsViewpointInsideOutsideVolume.h"

ARenderSettingsViewpointInsideOutsideVolume::ARenderSettingsViewpointInsideOutsideVolume() {
    this->TargetViewpointLerp = 1.00f;
    this->InsideMaxDifference = 0.50f;
    this->InsideMinDifference = 0.05f;
    this->ViewpointLerp = 0.00f;
}

