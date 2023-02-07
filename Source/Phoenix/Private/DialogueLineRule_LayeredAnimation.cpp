#include "DialogueLineRule_LayeredAnimation.h"

UDialogueLineRule_LayeredAnimation::UDialogueLineRule_LayeredAnimation() {
    this->Mask = NULL;
    this->ActiveWhen = ELineRule_LayeredAnimationType::OnlyWhenSpeaking;
    this->StartsFrom = ELineRule_LayeredAnimationStartFromType::DialogueLineStart;
    this->LipSyncIntensity = ELineRule_LayeredAnimationLipSyncIntensityType::LowToHigh;
    this->BlendWeight = 0.80f;
    this->BlendWeightVariability = 0.50f;
    this->ComputedBlendWeight = NULL;
    this->BlendTime = 0.40f;
    this->BlendTimeVariability = 0.10f;
    this->Blocking = false;
}

