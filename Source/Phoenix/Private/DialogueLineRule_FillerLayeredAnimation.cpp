#include "DialogueLineRule_FillerLayeredAnimation.h"

UDialogueLineRule_FillerLayeredAnimation::UDialogueLineRule_FillerLayeredAnimation() {
    this->Mask = NULL;
    this->ActiveWhen = ELineRule_LayeredAnimationType::OnlyWhenSpeaking;
    this->BlendWeight = 0.80f;
    this->BlendWeightVariability = 0.50f;
    this->ComputedBlendWeight = NULL;
    this->BlendTime = 0.40f;
    this->BlendTimeVariability = 0.10f;
    this->PaddingTime = 0.00f;
    this->PaddingTimeVariability = 0.00f;
    this->FitSmallAnimations = false;
}

