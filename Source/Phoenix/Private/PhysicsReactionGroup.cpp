#include "PhysicsReactionGroup.h"

FPhysicsReactionGroup::FPhysicsReactionGroup() {
    this->MinDamageThreshold = 0.00f;
    this->MunitionDataLevelAsset = NULL;
    this->CharacterDamage = 0.00f;
    this->NoiseSize = ENoiseSize::NoNoise;
}

