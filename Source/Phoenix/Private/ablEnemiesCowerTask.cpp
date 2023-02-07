#include "ablEnemiesCowerTask.h"

UablEnemiesCowerTask::UablEnemiesCowerTask() {
    this->FacialEmotion = EFacialEmotion::NONE;
    this->FacialEmotionPriority = EManagedFacialEmotionPriority::ABLE;
    this->TransitionTime = 0.75f;
}

