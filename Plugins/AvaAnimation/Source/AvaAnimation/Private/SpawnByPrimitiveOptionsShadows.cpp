#include "SpawnByPrimitiveOptionsShadows.h"

USpawnByPrimitiveOptionsShadows::USpawnByPrimitiveOptionsShadows() {
    this->ShadowMinLOD = -1;
    this->bCastShadow = true;
    this->bCastDynamicShadow = true;
    this->bCastStaticShadow = true;
    this->bCastVolumetricTranslucentShadow = false;
    this->bCastContactShadow = true;
    this->bSelfShadowOnly = false;
    this->bCastFarShadow = false;
    this->bCastInsetShadow = false;
    this->bCastCinematicShadow = false;
    this->bCastHiddenShadow = false;
    this->bCastShadowAsTwoSided = false;
}

