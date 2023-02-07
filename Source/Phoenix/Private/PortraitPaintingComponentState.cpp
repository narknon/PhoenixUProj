#include "PortraitPaintingComponentState.h"

FPortraitPaintingComponentState::FPortraitPaintingComponentState() {
    this->BoundsScale = 0.00f;
    this->CollisionEnabled = ECollisionEnabled::NoCollision;
    this->bUseAttachParentBound = false;
    this->bCastShadow = false;
    this->bCastContactShadow = false;
    this->bCastCapsuleDirectShadow = false;
    this->bReceivesDecals = false;
    this->bReceivesWeatherDecals = false;
    this->bIgnoreLightLeakingCorrection = false;
    this->bSetCollisionEnabled = false;
}

