#include "ObjectSizeClassStruct.h"

FObjectSizeClassStruct::FObjectSizeClassStruct() {
    this->Width = 0.00f;
    this->DamagePerSecondMultiplier = 0.00f;
    this->OnFireDestroyedAOE = NULL;
    this->OnFireDestroyedDamage = 0.00f;
    this->ObjectNoiseSize = ENoiseSize::NoNoise;
}

