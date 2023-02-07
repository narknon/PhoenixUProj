#include "CreatureSurfaceList.h"

FCreatureSurfaceList::FCreatureSurfaceList() {
    this->ParticleSystem = NULL;
    this->LocalParticleScale = 0.00f;
    this->ParticleKickupDirection = 0.00f;
    this->UseDecal = false;
    this->Decal = NULL;
    this->DirectionalDecal = false;
    this->DecalFrameCount = 0;
}

