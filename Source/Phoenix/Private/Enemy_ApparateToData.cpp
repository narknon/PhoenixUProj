#include "Enemy_ApparateToData.h"

FEnemy_ApparateToData::FEnemy_ApparateToData() {
    this->ApparateAbilityPtr = NULL;
    this->ApparateMode = EEnemy_AttackApparateMode::None;
    this->RangeMin = 0.00f;
    this->RangeMax = 0.00f;
    this->DistTolerance = 0.00f;
    this->TravelSpeed = 0.00f;
    this->OffsetZDist = 0.00f;
}

