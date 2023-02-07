#include "StencilPrimitiveClassFilter.h"

FStencilPrimitiveClassFilter::FStencilPrimitiveClassFilter() {
    this->Rule = EStencilRule::DoNotStencil;
    this->bIncludeSubclasses = false;
}

