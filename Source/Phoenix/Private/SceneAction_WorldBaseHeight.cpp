#include "SceneAction_WorldBaseHeight.h"

USceneAction_WorldBaseHeight::USceneAction_WorldBaseHeight() {
    this->WorldBaseHeightMeters = 0.00f;
    this->Affects = 7;
    this->RelativeTo = NULL;
    this->Priority = 1.00f;
    this->bPreviewOnly = false;
}

