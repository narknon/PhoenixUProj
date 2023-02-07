#include "BTT_Camera_AddCrossBlendBehavior.h"

UBTT_Camera_AddCrossBlendBehavior::UBTT_Camera_AddCrossBlendBehavior() {
    this->BehaviorClass = NULL;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->GroupIndex = -1;
    this->weight = 1.00f;
    this->CrossBlendSorting = ECameraStackBehaviorSorting::Oldest;
    this->FilterFlags = 0;
}

