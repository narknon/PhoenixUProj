#include "Enemy_ApparateActorData.h"

FEnemy_ApparateActorData::FEnemy_ApparateActorData() {
    this->Speed = 0.00f;
    this->Movement = EnemyApparateActor_Movement::ToLoc;
    this->Target = NULL;
    this->RangeToTarget = 0.00f;
    this->OffsetZDist = 0.00f;
    this->CapsuleRadius = 0.00f;
    this->CapsuleHalfHeight = 0.00f;
    this->MaxTime = 0.00f;
    this->bUseTravelTimeout = false;
}

