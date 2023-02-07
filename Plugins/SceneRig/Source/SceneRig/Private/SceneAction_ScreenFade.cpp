#include "SceneAction_ScreenFade.h"

USceneAction_ScreenFade::USceneAction_ScreenFade() {
    this->Fader = NULL;
    this->Type = EFadeType::FadeIn;
    this->ManualFadeValue = NULL;
    this->KeepStateOnCompletion = NULL;
    this->KeepFadeAfterSceneRigCompletion = NULL;
    this->FadeEventType = ETimeRigFadeEventType::None;
    this->EnableFading = NULL;
}

