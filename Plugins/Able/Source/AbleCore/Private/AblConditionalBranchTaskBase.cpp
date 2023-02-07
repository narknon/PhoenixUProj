#include "AblConditionalBranchTaskBase.h"

UAblConditionalBranchTaskBase::UAblConditionalBranchTaskBase() {
    this->bMustPassAllConditions = true;
    this->bOverrideAnimationBlendIn = false;
    this->bClampBlendOutTime = true;
    this->bOverrideRootMotion = false;
    this->SourceRootMotion = EEvaluatorRootMotion::ERM_StandardNoRotation;
    this->DestRootMotion = EEvaluatorRootMotion::ERM_StandardFullRotation;
    this->bOverrideBlendTickStyle = false;
    this->BlendTickStyleOverride = EAnimBlendTickStyle::BlendTickBoth;
}

