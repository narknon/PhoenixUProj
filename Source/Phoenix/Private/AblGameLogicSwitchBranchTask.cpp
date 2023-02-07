#include "AblGameLogicSwitchBranchTask.h"

UAblGameLogicSwitchBranchTask::UAblGameLogicSwitchBranchTask() {
    this->DefaultAbility = NULL;
    this->m_CopyTargetsOnBranch = false;
    this->m_bOverrideTransitionBlend = true;
    this->m_bOverrideTransitionBlendOut = false;
    this->bClampBlendOutTime = true;
    this->m_UseSourceRootMotion = EEvaluatorRootMotion::ERM_StandardNoRotation;
    this->m_UseDestRootMotion = EEvaluatorRootMotion::ERM_StandardFullRotation;
    this->m_OverrideRootMotion = false;
    this->m_OverrideBlendTickStyle = false;
    this->m_BlendTickStyle = EAnimBlendTickStyle::BlendTickBoth;
}

