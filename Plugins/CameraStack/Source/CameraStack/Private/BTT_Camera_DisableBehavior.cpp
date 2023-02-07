#include "BTT_Camera_DisableBehavior.h"

UBTT_Camera_DisableBehavior::UBTT_Camera_DisableBehavior() {
    this->BehaviorClass = NULL;
    this->BehaviorSorting = ECameraStackBehaviorSorting::Oldest;
    this->FilterFlags = 0;
    this->BlendOutDuration = 0.00f;
    this->BlendInDuration = 0.00f;
    this->bReturnImmediately = false;
}

