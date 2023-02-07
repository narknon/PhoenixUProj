#include "EnemyAIAttackBaseData.h"

UEnemyAIAttackBaseData::UEnemyAIAttackBaseData() {
    this->MaxMoveAngle = 180.00f;
    this->bOverrideMobilityMoveThreshold = false;
    this->MoveDistThreshold = 250.00f;
    this->MoveDistThresholdNoMansLandScale = 1.50f;
    this->MoveDistThresholdNoMansLandScaleCloser = 0.75f;
    this->ApproachDataList.AddDefaulted(3);
}

