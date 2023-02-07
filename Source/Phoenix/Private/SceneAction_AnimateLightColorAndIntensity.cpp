#include "SceneAction_AnimateLightColorAndIntensity.h"

USceneAction_AnimateLightColorAndIntensity::USceneAction_AnimateLightColorAndIntensity() {
    this->ColorBlend = EAnimateLightColorIntensityBlend::Replace;
    this->IntensityBlend = EAnimateLightColorIntensityBlend::Replace;
}

