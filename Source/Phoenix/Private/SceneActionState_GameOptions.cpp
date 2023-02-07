#include "SceneActionState_GameOptions.h"

USceneActionState_GameOptions::USceneActionState_GameOptions() {
    this->CachedTime = -1.00f;
    this->CachedDuration = -1.00f;
    this->bCachedEnabled = false;
    this->bCachedInsideInterval = false;
}

