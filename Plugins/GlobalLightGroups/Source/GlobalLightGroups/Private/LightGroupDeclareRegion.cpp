#include "LightGroupDeclareRegion.h"

ALightGroupDeclareRegion::ALightGroupDeclareRegion(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FXList = NULL;
    this->Priority = 0.00f;
    this->bUnbounded = false;
}

