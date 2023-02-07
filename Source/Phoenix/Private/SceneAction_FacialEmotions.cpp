#include "SceneAction_FacialEmotions.h"

USceneAction_FacialEmotions::USceneAction_FacialEmotions() {
    this->Emotion = EFacialEmotion::NONE;
    this->Priority = EManagedFacialEmotionPriority::SCENERIG;
    this->BlendInTime = 0.50f;
}

