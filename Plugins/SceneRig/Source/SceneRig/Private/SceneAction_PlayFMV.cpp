#include "SceneAction_PlayFMV.h"

USceneAction_PlayFMV::USceneAction_PlayFMV() {
    this->MediaSource = NULL;
    this->bOverridesSceneRig = true;
    this->FudgeFactor = 0.13f;
}

