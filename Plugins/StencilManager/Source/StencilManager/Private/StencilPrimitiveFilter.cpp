#include "StencilPrimitiveFilter.h"

FStencilPrimitiveFilter::FStencilPrimitiveFilter() {
    this->Rule = EStencilRule::DoNotStencil;
    this->MatchMode = EStencilFilterPrimitiveMatchMode::Exact;
}

