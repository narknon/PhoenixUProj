#include "StencilValueRenderCustomDepthFilter.h"

FStencilValueRenderCustomDepthFilter::FStencilValueRenderCustomDepthFilter() {
    this->Rule = EStencilValueRenderCustomDepthRule::DoNotStencil;
    this->bExcludeFX = false;
}

