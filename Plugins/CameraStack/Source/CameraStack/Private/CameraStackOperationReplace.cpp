#include "CameraStackOperationReplace.h"

UCameraStackOperationReplace::UCameraStackOperationReplace() {
    this->Behavior = NULL;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->BehaviorSorting = ECameraStackBehaviorSorting::Oldest;
    this->FilterFlags = 0;
    this->bLazyBlendOut = false;
    this->bReuseBehaviorOnReactivate = true;
}

