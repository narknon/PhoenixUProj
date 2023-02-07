#include "MultiFX2_Decal.h"

UMultiFX2_Decal::UMultiFX2_Decal() {
    this->bAttached = false;
    this->Material = NULL;
    this->FadeInDelay = 0.00f;
    this->FadeInTime = 0.00f;
    this->LifeSpan = 10.00f;
    this->FadeTime = 2.00f;
    this->DecalOrientation = EDecalOrientation::Random;
}

