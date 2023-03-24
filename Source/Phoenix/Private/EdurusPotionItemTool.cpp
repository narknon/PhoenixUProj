#include "EdurusPotionItemTool.h"

AEdurusPotionItemTool::AEdurusPotionItemTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_RelativeSpawnBoneName = TEXT("Spine3");
    this->m_MinRockDamage = 100.00f;
    this->m_MaxRockDamage = 200.00f;
    this->m_EnemySeekRadius = 500.00f;
    this->m_MinDistFromOwner = 10.00f;
    this->m_MaxDistFromOwner = 25.00f;
    this->m_MinRockLaunchTime = 1.00f;
    this->m_MaxRockLaunchTime = 5.00f;
    this->m_MinNumRocks = 5;
    this->m_MaxNumRocks = 10;
    this->m_RockMunition = NULL;
}

