#include "CameraStackBehaviorMultiCrossBlend.h"

class UCameraStack;
class UCameraStackBehaviorMultiCrossBlend;

TArray<FCameraCrossBlendBehaviorGroup> UCameraStackBehaviorMultiCrossBlend::GetCrossBlendBehaviorGroups() const {
    return TArray<FCameraCrossBlendBehaviorGroup>();
}

UCameraStackBehaviorMultiCrossBlend* UCameraStackBehaviorMultiCrossBlend::CreateMultiCrossBlendBehavior(UCameraStack* InCameraStack, float InMaxCrossBlendSpeed) {
    return NULL;
}

UCameraStackBehaviorMultiCrossBlend::UCameraStackBehaviorMultiCrossBlend() {
    this->MaxCrossBlendSpeed = 10.00f;
}

