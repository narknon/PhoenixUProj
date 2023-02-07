#include "PathNode.h"

class AActor;

float APathNode::GetArrivalTimeout() const {
    return 0.0f;
}

void APathNode::BroadcastArrived(AActor* pActor) {
}


APathNode::APathNode() {
    this->m_waitTime = 0.00f;
    this->m_threshold = 100.00f;
    this->m_arrivalTimeout = -1.00f;
    this->m_nextAction = EEnemyAIState::Wander;
    this->m_onArrivalEnablePerception = false;
    this->m_applyPathSpeed = false;
    this->m_selectedSpeed = EPathNodeSpeed::Custom;
    this->m_pathSpeed = 200.00f;
    this->m_airPathNode = false;
    this->m_airPathSpeedMultiplyer = 1.00f;
    this->m_perchPathNode = false;
}

