#include "ActorMeshSetupProcessShadows.h"

UActorMeshSetupProcessShadows::UActorMeshSetupProcessShadows() {
    this->bCastShadow = true;
    this->bCastDynamicShadow = true;
    this->bCastStaticShadow = true;
    this->bCastContactShadow = false;
    this->NoContactShadowTag = TEXT("DontCastContactShadow");
    this->bOverride_bCastShadow = false;
    this->bOverride_bCastDynamicShadow = false;
    this->bOverride_bCastStaticShadow = false;
    this->bOverride_bCastContactShadow = false;
}

