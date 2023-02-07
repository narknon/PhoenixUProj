#include "SceneAction_PlayBinkMedia.h"

USceneAction_PlayBinkMedia::USceneAction_PlayBinkMedia() {
    this->MediaSource = NULL;
    this->SubtitlesDataTable = NULL;
    this->bOverridesSceneRig = true;
    this->EffectVolumeFactor = 0.85f;
    this->VoiceVolumeFactor = 0.85f;
    this->FudgeFactor = 0.00f;
    this->bDelayedOpen = false;
    this->WidgetClass = NULL;
    this->Opacity = NULL;
    this->ForegroundOpacity = NULL;
}

