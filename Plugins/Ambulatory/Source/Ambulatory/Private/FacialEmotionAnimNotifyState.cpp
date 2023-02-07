#include "FacialEmotionAnimNotifyState.h"

UFacialEmotionAnimNotifyState::UFacialEmotionAnimNotifyState() {
    this->FacialEmotion = EFacialEmotion::NONE;
    this->TransitionTime = 0.25f;
    this->FacialEmotionPriority = EManagedFacialEmotionPriority::ANIM;
}

