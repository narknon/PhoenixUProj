#include "MultiFX2PostProcessComponent.h"

UMultiFX2PostProcessComponent::UMultiFX2PostProcessComponent() {
    this->Definition = NULL;
    this->BlendWeight = 1.00f;
    this->FadeBlendWeight = 1.00f;
    this->FadeSpeed = 0.00f;
    this->DefaultFadeOutTime = 1.00f;
    this->AutoFadeOutTime = -1.00f;
    this->Birth = 0.00f;
    this->Priority = 200.00f;
}

