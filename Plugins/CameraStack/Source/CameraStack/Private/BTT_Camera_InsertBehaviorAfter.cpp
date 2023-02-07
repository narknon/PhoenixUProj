#include "BTT_Camera_InsertBehaviorAfter.h"

UBTT_Camera_InsertBehaviorAfter::UBTT_Camera_InsertBehaviorAfter() {
    this->BehaviorClass = NULL;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->InsertAfterBehaviorSorting = ECameraStackBehaviorSorting::Oldest;
    this->FilterFlags = 0;
    this->bReuseBehaviorOnReactivate = true;
}

