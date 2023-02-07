#include "Objectfade.h"

FObjectfade::FObjectfade() {
    this->TimeFactor = 0.00f;
    this->Age = 0.00f;
    this->Opacity = 0.00f;
    this->Delay = 0.00f;
    this->FadeCompletedAction = EObjectFadeCompletedAction::Default;
    this->bDone = false;
    this->bReverseTime = false;
    this->bHiddenAtEnd = false;
}

