#include "SceneRigAnimationClipRange.h"

FSceneRigAnimationClipRange::FSceneRigAnimationClipRange() {
    this->RangeType = ESceneRigAnimationPlaybackRange::FullClipRange;
    this->TimingOffset = NULL;
    this->StartOffset = NULL;
    this->EndOffset = NULL;
    this->Duration = NULL;
}

