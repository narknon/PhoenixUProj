#include "CameraStackInfluenceHandle.h"

void UCameraStackInfluenceHandle::SetInfluenceWeight(float NewWeight) {
}

UCameraStackInfluenceHandle::UCameraStackInfluenceHandle() {
    this->Preset = NULL;
    this->Priority = 0;
    this->MaxBlendSpeed = 340282346638528859811704183484516925440.00f;
    this->weight = 0.00f;
}

