#include "AnimationTransformProvider.h"

UAnimationTransformProvider::UAnimationTransformProvider() {
    this->AnimationProvider = NULL;
    this->bUseAnimationTime = true;
    this->PlaybackFraction = 0.00f;
}

