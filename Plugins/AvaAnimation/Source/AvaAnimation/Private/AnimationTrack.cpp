#include "AnimationTrack.h"

FAnimationTrack::FAnimationTrack() {
    this->Animation = NULL;
    this->LocalAnimDuration = 0.00f;
    this->PlayRate = 0.00f;
    this->LocalAnimStart = 0.00f;
    this->TimingOffset = 0.00f;
    this->AnimStart = 0.00f;
    this->AnimEnd = 0.00f;
    this->CurrentLocalTime = 0.00f;
    this->PreviousLocalTime = 0.00f;
    this->CurrentTime = 0.00f;
    this->CurrentBlendWeight = 0.00f;
    this->AnimationProvider = NULL;
    this->BlendSpaceInput = NULL;
    this->ReselectOnLoopBoundaries = false;
}

