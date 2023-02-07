#include "AnimationRequestLayer.h"

FAnimationRequestLayer::FAnimationRequestLayer() {
    this->MaxLODLevel = 0;
    this->BlendType = EAnimationRequestLayerBlendType::Replacement;
    this->bRecordLastSequence = false;
    this->LayerMask = NULL;
}

