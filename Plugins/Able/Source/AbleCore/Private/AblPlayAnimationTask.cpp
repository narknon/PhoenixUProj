#include "AblPlayAnimationTask.h"

UAblPlayAnimationTask::UAblPlayAnimationTask() {
    this->m_AnimationAssetChooser = NULL;
    this->m_AnimationAsset = NULL;
    this->m_BlendSpaceParameterGetter = NULL;
    this->m_AnimRateGetter = NULL;
    this->m_StartPositionGetter = NULL;
    this->m_BlendWeightMultiplierGetter = NULL;
    this->m_AnimationMode = AbilityAnimationNode;
    this->m_OverrideBlendOut = false;
    this->m_Loop = false;
    this->m_PlayRate = 1.00f;
    this->m_ScaleWithAbilityPlayRate = true;
    this->m_StopAnimationOnInterrupt = true;
    this->m_MatchPhase = false;
    this->m_PlayOnServer = false;
    this->m_bOverrideAnimGraphRootMotionProperties = true;
    this->m_BoneWeightAsset = NULL;
    this->m_RotationOffsetMeshSpace = false;
    this->m_IsAdditive = false;
}

