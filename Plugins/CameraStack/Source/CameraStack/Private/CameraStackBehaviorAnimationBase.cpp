#include "CameraStackBehaviorAnimationBase.h"

UCameraStackBehaviorAnimationBase::UCameraStackBehaviorAnimationBase() {
    this->LoopMode = ECameraStackAnimationLoopMode::Loop;
    this->AnimationFrame = ECameraStackAnimationFrame::RelativeToTarget;
    this->SecondaryTarget = NULL;
    this->PlayRate = 1.00f;
    this->AnimSequence = NULL;
}

