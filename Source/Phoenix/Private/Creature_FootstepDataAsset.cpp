#include "Creature_FootstepDataAsset.h"

UCreature_FootstepDataAsset::UCreature_FootstepDataAsset() {
    this->AudioMaxDistanceToCamera = 5000.00f;
    this->AudioEvent = NULL;
    this->AudioImpactStrengthArray[0] = 100.00f;
    this->AudioImpactStrengthArray[1] = 100.00f;
    this->AudioImpactStrengthArray[2] = 100.00f;
    this->MotionEvent = NULL;
    this->PlayerMountedMotionEvent = NULL;
    this->ParticlesMaxLOD = 3;
    this->ParticlesMaxDistanceToCamera = 2500.00f;
    this->DecalScale = 0.00f;
    this->EffectScale = 0.00f;
}

