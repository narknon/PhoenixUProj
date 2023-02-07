#include "SavePrimitiveRenderCustomDepth.h"

FSavePrimitiveRenderCustomDepth::FSavePrimitiveRenderCustomDepth() {
    this->StencilValue = 0;
    this->bRenderCustomDepth = false;
    this->bManageVisibility = false;
    this->bVisible = false;
}

