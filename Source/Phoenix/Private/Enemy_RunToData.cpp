#include "Enemy_RunToData.h"

FEnemy_RunToData::FEnemy_RunToData() {
    this->RunToRangeMin = 0.00f;
    this->RunToRangeMax = 0.00f;
    this->RunMinDist = 0.00f;
    this->DistTolerance = 0.00f;
    this->Timeout = 0.00f;
    this->AbortDist = 0.00f;
    this->PreMoveStartAbility = NULL;
    this->ParryRunToType = EEnemy_ParryRunToType::LeadInAndRelease;
    this->ParryRunToSpeedEstimate = 0.00f;
    this->ParryRunToUseVelocityInAttackTimeOfImpact = false;
}

