#include "ActorMeshSetupProcessContactShadow.h"

UActorMeshSetupProcessContactShadow::UActorMeshSetupProcessContactShadow() {
    this->bCastContactShadow = true;
    this->NoContactShadowTag = TEXT("DontCastContactShadow");
}

