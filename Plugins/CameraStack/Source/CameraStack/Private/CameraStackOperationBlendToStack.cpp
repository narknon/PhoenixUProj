#include "CameraStackOperationBlendToStack.h"

UCameraStackOperationBlendToStack::UCameraStackOperationBlendToStack() {
    this->StackSettings = NULL;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->bLazyBlendOut = false;
    this->bReuseBehaviorOnReactivate = true;
}

