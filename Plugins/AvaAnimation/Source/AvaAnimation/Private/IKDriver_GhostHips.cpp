#include "IKDriver_GhostHips.h"

UIKDriver_GhostHips::UIKDriver_GhostHips() {
    this->AlphaVariableName = TEXT("HipAlpha");
    this->TransformVariableName = TEXT("HipTransform");
    this->InterpSpeed = 5.00f;
    this->InterpDampingFactor = 1.00f;
}

