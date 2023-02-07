#include "SaveAndOverridePrimitiveRenderCustomDepthOwner.h"

FSaveAndOverridePrimitiveRenderCustomDepthOwner::FSaveAndOverridePrimitiveRenderCustomDepthOwner() {
    this->StencilValueOverride = 0;
    this->bRenderCustomDepthOverride = false;
    this->bOverridestencilValue = false;
    this->bOverrideRenderCustomDepth = false;
}

