#include "EnemyAIPropertyData.h"

UEnemyAIPropertyData::UEnemyAIPropertyData() {
    this->m_sizeCategory = EEEnemyAISizeCategory::Medium;
    this->RotationRate = 50.00f;
    this->FleeFixedDistance = 1000.00f;
    this->PathCheckPtr = NULL;
}

