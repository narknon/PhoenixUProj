#include "ablTurnAdjustTask.h"

UablTurnAdjustTask::UablTurnAdjustTask() {
    this->m_MaxAdjustAngle = 180.00f;
    this->m_TrackTarget = true;
    this->m_TargetDirectionGetter = NULL;
    this->m_YawOffset = 0.00f;
    this->m_bOverrideRootMotionLookAheadTime = false;
    this->m_RootMotionLookAheadTime = 1.00f;
    this->m_bUseTaskEndTime = false;
    this->bGuaranteeOnTargetAtTaskEnd = false;
    this->m_bDebugDraw = false;
}

