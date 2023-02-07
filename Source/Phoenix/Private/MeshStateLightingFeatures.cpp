#include "MeshStateLightingFeatures.h"

FMeshStateLightingFeatures::FMeshStateLightingFeatures() {
    this->bCastShadows = false;
    this->bCastDynamicShadow = false;
    this->bCastContactShadow = false;
    this->bCastCapsuleDirectShadow = false;
    this->bOverride_bCastShadows = false;
    this->bOverride_bCastDynamicShadow = false;
    this->bOverride_bCastContactShadow = false;
    this->bOverride_bCastCapsuleDirectShadow = false;
}

