#include "MaterialSwapDependentRules.h"

FMaterialSwapDependentRules::FMaterialSwapDependentRules() {
    this->bComponentChildren = false;
    this->bDirectChildren = false;
    this->bAttachedChildren = false;
    this->bLimitDepth = false;
    this->MaxDepth = 0;
}

