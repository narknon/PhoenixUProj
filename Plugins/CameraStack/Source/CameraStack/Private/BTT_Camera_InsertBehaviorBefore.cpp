#include "BTT_Camera_InsertBehaviorBefore.h"

UBTT_Camera_InsertBehaviorBefore::UBTT_Camera_InsertBehaviorBefore() {
    this->BehaviorClass = NULL;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->InsertBeforeBehaviorSorting = ECameraStackBehaviorSorting::Oldest;
    this->FilterFlags = 0;
    this->bReuseBehaviorOnReactivate = true;
}

