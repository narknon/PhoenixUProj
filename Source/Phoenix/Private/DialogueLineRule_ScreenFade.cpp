#include "DialogueLineRule_ScreenFade.h"

UDialogueLineRule_ScreenFade::UDialogueLineRule_ScreenFade() {
    this->OffsetFromDialogueLine = 0.00f;
    this->InitialScreenFade = NULL;
    this->FinalScreenFade = NULL;
    this->BlendTime = NULL;
    this->FadeEventType = ETimeRigFadeEventType::None;
    this->KeepStateOnCompletion = NULL;
    this->KeepFadeAfterSceneRigCompletion = NULL;
    this->EnableFading = NULL;
}

