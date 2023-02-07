#include "StencilManagerEffectInfo.h"

FStencilManagerEffectInfo::FStencilManagerEffectInfo() {
    this->LegacyStencilValue = 0;
    this->Priority = EStencilManagerEffectPriority::AlwaysInterrupt;
    this->PreferredEffect = EStencilManagerPreferredEffect::LocalDepthFX;
    this->bDisableOverrides = false;
}

