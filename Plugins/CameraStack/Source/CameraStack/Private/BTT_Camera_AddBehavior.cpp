#include "BTT_Camera_AddBehavior.h"

UBTT_Camera_AddBehavior::UBTT_Camera_AddBehavior() {
    this->BehaviorClass = NULL;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->bReuseBehaviorOnReactivate = true;
}

