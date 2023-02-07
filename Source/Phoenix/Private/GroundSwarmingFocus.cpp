#include "GroundSwarmingFocus.h"

FGroundSwarmingFocus::FGroundSwarmingFocus() {
    this->Type = EGroundSwarmingFocusType::Undefined;
    this->TypeHint = EGroundSwarmingFocusTypeHint::None;
    this->bBoundsIncludeNonColliding = false;
    this->bCacheBounds = false;
}

