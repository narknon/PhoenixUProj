#include "SceneActionState_Animation.h"

USceneActionState_Animation::USceneActionState_Animation() {
    this->MaxWeight = 0.00f;
    this->BlendInTime = 0.00f;
    this->BlendOutTime = 0.00f;
    this->CurrentBlendWeight = 0.00f;
    this->CurrentlyInBlendInTime = false;
    this->CurrentlyInBlendOutTime = false;
    this->ShouldBeRegistered = false;
    this->AnimationComponent = NULL;
}

