#include "BTT_Camera_PauseBehavior.h"

UBTT_Camera_PauseBehavior::UBTT_Camera_PauseBehavior() {
    this->BehaviorClass = NULL;
    this->BehaviorSorting = ECameraStackBehaviorSorting::Oldest;
    this->FilterFlags = 0;
    this->bReturnImmediately = false;
}

