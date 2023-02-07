#include "AnimationClip_TagLookupAndMatchTransform.h"

UAnimationClip_TagLookupAndMatchTransform::UAnimationClip_TagLookupAndMatchTransform() {
    this->TransformToMatchProvider = NULL;
    this->AnchorTransformProvider = NULL;
    this->AnimationMatchFlag = MATCH_LAST_FRAME;
    this->FetchAnims = ANIMFETCH_UNKNOWN;
    this->bSearchAnimationArchitect = true;
}

