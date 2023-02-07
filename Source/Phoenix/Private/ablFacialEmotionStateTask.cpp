#include "ablFacialEmotionStateTask.h"

UablFacialEmotionStateTask::UablFacialEmotionStateTask() {
    this->FacialEmotion = EFacialEmotion::NONE;
    this->FacialEmotionPriority = EManagedFacialEmotionPriority::ABLE;
    this->TransitionTime = 0.75f;
}

