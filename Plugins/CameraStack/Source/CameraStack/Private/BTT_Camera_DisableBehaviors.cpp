#include "BTT_Camera_DisableBehaviors.h"

UBTT_Camera_DisableBehaviors::UBTT_Camera_DisableBehaviors() {
    this->BehaviorSorting = ECameraStackBehaviorSorting::Oldest;
    this->FilterFlags = 0;
    this->BlendOutDuration = 0.00f;
    this->BlendInDuration = 0.00f;
}

