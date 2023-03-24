#include "CrowdTest.h"

ACrowdTest::ACrowdTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_minDesiredSpeed = 250.00f;
    this->m_maxDesiredSpeed = 350.00f;
    this->m_spawnCount = 0;
    this->m_arrivedCount = 0;
}

