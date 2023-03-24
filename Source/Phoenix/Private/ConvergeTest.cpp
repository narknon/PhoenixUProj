#include "ConvergeTest.h"

AConvergeTest::AConvergeTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_radius = 1000.00f;
    this->m_desiredSpeed = 300.00f;
    this->m_pathCount = 1;
    this->m_opposing = false;
}

