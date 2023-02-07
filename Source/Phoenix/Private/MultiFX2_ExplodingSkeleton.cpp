#include "MultiFX2_ExplodingSkeleton.h"

UMultiFX2_ExplodingSkeleton::UMultiFX2_ExplodingSkeleton() {
    this->Info = NULL;
    this->PieceSetup = NULL;
    this->bUseLinearImpulseOrigin = false;
    this->bUseInstigatorToTargetAsX = false;
    this->bUseNpcImpactDataForImpulse = false;
    this->LinearImpulseStrength = 0.00f;
    this->RadialImpulseRadius = 100.00f;
    this->RadialImpulseStrength = 0.00f;
    this->bRadialImpulseFalloff = true;
    this->bUseSkeletalCentroidAsImpulseOrigin = false;
}

