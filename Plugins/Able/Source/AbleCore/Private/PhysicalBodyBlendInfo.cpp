#include "PhysicalBodyBlendInfo.h"

UPhysicalBodyBlendInfo::UPhysicalBodyBlendInfo() {
    this->BlendState = EPhysicalBodyBlendState::None;
    this->ChannelIndex = 0;
    this->bContinuous = true;
    this->bMarkedForDestroy = false;
}

