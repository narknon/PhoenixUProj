#include "AblEnemyAttackTargetSyncPointUpdater.h"

UAblEnemyAttackTargetSyncPointUpdater::UAblEnemyAttackTargetSyncPointUpdater() {
    this->DesiredDistanceToTarget = 0.00f;
    this->bAllowPositiveTravel = true;
    this->bAllowNegativeTravel = true;
}

