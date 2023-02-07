#include "SocialDisplayManager.h"

USocialDisplayManager::USocialDisplayManager() {
    this->m_lookAheadTime = 3.00f;
    this->m_borderLookAheadTime = 0.50f;
    this->m_logConstraintAllocation = false;
    this->m_logAgentPairs = false;
    this->m_enableAgentSelection = true;
    this->m_drawVelocityObstacles = false;
    this->m_drawOptimalConstraints = false;
    this->m_drawPenetratingConstraints = false;
    this->m_debugFrameCount = 300;
    this->m_debugFrameOffset = 0;
}

