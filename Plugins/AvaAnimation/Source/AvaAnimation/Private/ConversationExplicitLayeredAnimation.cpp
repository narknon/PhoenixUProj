#include "ConversationExplicitLayeredAnimation.h"

FConversationExplicitLayeredAnimation::FConversationExplicitLayeredAnimation() {
    this->Mask = NULL;
    this->BlendWeight = 0.00f;
    this->BlendWeightVariability = 0.00f;
    this->ComputedBlendWeight = NULL;
    this->BlendTime = 0.00f;
    this->BlendTimeVariability = 0.00f;
    this->Blocking = false;
}

