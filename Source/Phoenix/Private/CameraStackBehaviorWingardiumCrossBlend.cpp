#include "CameraStackBehaviorWingardiumCrossBlend.h"

UCameraStackBehaviorWingardiumCrossBlend::UCameraStackBehaviorWingardiumCrossBlend() {
    this->Target = NULL;
    this->MinTargetHeight = -200.00f;
    this->MaxTargetHeight = -100.00f;
    this->ProbeSize = 32.00f;
    this->ProbeChannel = ECC_Camera;
}

