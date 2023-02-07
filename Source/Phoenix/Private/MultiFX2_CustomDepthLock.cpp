#include "MultiFX2_CustomDepthLock.h"

UMultiFX2_CustomDepthLock::UMultiFX2_CustomDepthLock() {
    this->StencilValue = 1;
    this->bRenderCustomDepth = true;
    this->StencilLockPriority = 0;
}

