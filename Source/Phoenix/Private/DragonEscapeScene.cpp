#include "DragonEscapeScene.h"

void ADragonEscapeScene::QueueFinalRelease() {
}

void ADragonEscapeScene::PlaySceneRig() {
}

void ADragonEscapeScene::PlayQueuedFinalRelease() {
}

ADragonEscapeScene::ADragonEscapeScene() {
    this->m_SceneRigPlayer = NULL;
    this->m_DragonEscapeSceneRig = NULL;
    this->ParameterBlock = NULL;
    this->AIDragon = NULL;
    this->DragonPlatform = NULL;
}

