#include "EnemyAwarenessAmendInfo.h"

FEnemyAwarenessAmendInfo::FEnemyAwarenessAmendInfo() {
    this->AwareState = NPC_TargetAwareStateRateSource::EnterAware;
    this->DistFromPlayer = 0.00f;
}

