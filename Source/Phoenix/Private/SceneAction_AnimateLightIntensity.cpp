#include "SceneAction_AnimateLightIntensity.h"

USceneAction_AnimateLightIntensity::USceneAction_AnimateLightIntensity() {
    this->Default = 0.00f;
    this->Blend = EAnimateLightColorIntensityBlend::Replace;
}

