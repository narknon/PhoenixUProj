#include "AblPlayAnimationArchitectTask.h"

UAblPlayAnimationArchitectTask::UAblPlayAnimationArchitectTask() {
    this->m_AnimationAssetChooser = NULL;
    this->m_AnimTransitionInOverriderer = NULL;
    this->m_AnimationTagChooser = NULL;
    this->m_BlendSpaceParameterGetter = NULL;
    this->m_AnimRateGetter = NULL;
    this->m_StartPositionGetter = NULL;
    this->m_BlendWeightMultiplierGetter = NULL;
    this->m_EndCallback = NULL;
    this->m_BlendTickStyle = EAnimBlendTickStyle::BlendTickBoth;
    this->m_OverrideBlendOut = false;
    this->bFadeOutToEndOfAnimation = true;
    this->m_Loop = false;
    this->m_PlayRate = 1.00f;
    this->m_ScaleWithAbilityPlayRate = true;
    this->m_MatchPhase = false;
    this->m_PlayOnServer = false;
    this->m_BoneWeightAsset = NULL;
    this->m_RotationOffsetMeshSpace = false;
    this->m_IsAdditive = false;
    this->m_IsFacialAnimation = false;
}

