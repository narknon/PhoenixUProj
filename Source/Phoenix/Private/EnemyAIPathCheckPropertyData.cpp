#include "EnemyAIPathCheckPropertyData.h"

UEnemyAIPathCheckPropertyData::UEnemyAIPathCheckPropertyData() {
    this->MinTime = 0.45f;
    this->MaxTime = 0.55f;
    this->StartOffset = 100.00f;
    this->MaxDist = 400.00f;
    this->AttackPosLockLocTime = 1.50f;
    this->SwappedLockLocTime = 1.50f;
    this->OpeningLockLocTime = 1.50f;
    this->UseSweepSphere = true;
    this->SweepSphereRadius = 20.00f;
}

