#include "ExplodingSkeletonImpulse.h"

FExplodingSkeletonImpulse::FExplodingSkeletonImpulse() {
    this->bUseLinearImpulseOrigin = false;
    this->RadialImpulseRadius = 0.00f;
    this->RadialImpulseStrength = 0.00f;
    this->bRadialImpulseFalloff = false;
    this->bUseSkeletalCentroidAsImpulseOrigin = false;
}

